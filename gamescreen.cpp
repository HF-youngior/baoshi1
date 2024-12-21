/**
 * GameScreen（游戏界面类）：绘制游戏UI界面
 * initBoard():初始化界面矩阵信息
 * updateGemImage(QPushButton *button, int row, int col)：设置宝石图像，可以通过切换路径修改图像
 * updateBoard()：更新界面矩阵信息，如按钮等
 * on_shopButton_clicked()：单击以打开商店界面
 * on_exitButton_clicked()：单击以退出游戏
 * onGemClicked(int row, int col)：点击宝石后进行的操作，即实现游戏逻辑
 * updateScore(int newScore)：显示分数
*/

#include "ui_gamescreen.h"
#include "gamescreen.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QFont>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPushButton>
#include <QRandomGenerator>
#include <algorithm>
#include <random>
#include <QMessageBox>
#include <QTimer>

GameScreen::GameScreen(const QString &userEmail, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameScreen)
    , userEmail(userEmail)  // 保存传入的邮箱
    , isPaused(false)
{
    ui->setupUi(this);

    // 设置整个页面大小
    this->setFixedSize(900, 650);
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 初始化分数显示标签
    scoreLabel = new QLabel(this);
    scoreLabel->setText("分数: 0");
    scoreLabel->setAlignment(Qt::AlignCenter);
    scoreLabel->setFixedSize(200, 40);
    scoreLabel->move(350, 590);
    QFont font("Arial", 20, QFont::Bold);
    scoreLabel->setFont(font);

    // 添加分数标签到布局
    layout->addWidget(scoreLabel);

    // 打印调试信息
    qDebug() << "User Email: " << userEmail;

    // 初始化游戏引擎
    // 在 GameScreen.cpp 中
    gameEngine = new GameEngine(userEmail, this);  // 传递 email 到 GameEngine

    connect(gameEngine, &GameEngine::updateBoard, this, &GameScreen::updateBoard);
    connect(gameEngine, &GameEngine::scoreChanged, this, &GameScreen::updateScore);

    initBoard();  // 初始化游戏板


    connect(ui->shopButton, &QPushButton::clicked, this, &GameScreen::on_shopButton_clicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &GameScreen::on_exitButton_clicked);
    connect(ui->pauseButton, &QPushButton::clicked, this, &GameScreen::pauseGame); // 暂停按钮

    progressBar = ui->progressBar;
    progressBar->setTextVisible(false);// 隐藏进度条进度
    timeLabel = ui->timeLabel;
    QPalette palette = this->palette();
    QColor backgroundColor = palette.color(QPalette::Window); // 获取窗口的背景颜色
    timeLabel->setStyleSheet(QString("background-color: %1;").arg(backgroundColor.name()));// 让QLabel显示背景颜色
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GameScreen::updateProgressBar);
    connect(timer, &QTimer::timeout, this, &GameScreen::updateTimeLabel);
    timeLeft = 30; // 设置倒计时时间为30秒

     // 初始化技能标签
    // 假设 skillLabel 已经在 UI 中定义了，不需要重新创建
    skillLabel=ui->skillLabel;
    skillLabel->setText("药水数量: \n重置药水: 0,\n 冷冻药水: 0, \n超级药水: 0");
    skillLabel->setAlignment(Qt::AlignCenter);
    skillLabel->setFont(QFont("Arial", 8));


    resetPotionCount = 0;
    freezePotionCount = 0;
    superPotionCount = 0;

    // 连接信号来更新药水数量
    connect(this, &GameScreen::resetPotionPurchased, this, &GameScreen::on_resetPotionPurchased);
    connect(this, &GameScreen::freezePotionPurchased, this, &GameScreen::on_freezePotionPurchased);
    connect(this, &GameScreen::superPotionPurchased, this, &GameScreen::on_superPotionPurchased);

}

GameScreen::~GameScreen()
{
    delete ui;
}

void GameScreen::initBoard()
{
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(0);

    QWidget *boardWidget = new QWidget(this);
    boardWidget->setLayout(gridLayout);
    boardWidget->setFixedSize(480, 480);
    boardWidget->move(410, 50);

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QPushButton *gemButton = new QPushButton(boardWidget);
            gemButton->setFixedSize(60, 60);
            gridLayout->addWidget(gemButton, row, col);

            updateGemImage(gemButton, row, col);

            buttons[row][col] = gemButton;
            connect(gemButton, &QPushButton::clicked, [this, row, col](){ onGemClicked(row, col); });
        }
    }

    gameEngine->startGame();  // 启动游戏
}

void GameScreen::updateGemImage(QPushButton *button, int row, int col)
{
    QString gemType = gameEngine->getGemAt(row, col);  // 获取宝石类型
    QString gemImagePath;

    if (gemType == "Gem1") {
        gemImagePath = ":/new/prefix1/image/1.bmp";
    } else if (gemType == "Gem2") {
        gemImagePath = ":/new/prefix1/image/2.bmp";
    } else if (gemType == "Gem3") {
        gemImagePath = ":/new/prefix1/image/3.bmp";
    } else if (gemType == "Gem4") {
        gemImagePath = ":/new/prefix1/image/4.bmp";
    }

    QPixmap pixmap(gemImagePath);
    button->setIcon(pixmap);
    button->setIconSize(pixmap.size());
}

void GameScreen::updateBoard()
{
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QPushButton *button = buttons[row][col];
            updateGemImage(button, row, col);
        }
    }
}

void GameScreen::updateScore(int newScore)
{
    if (scoreLabel) {
        scoreLabel->setText("分数: " + QString::number(newScore));  // 显示新的分数
    }
}

void GameScreen::on_shopButton_clicked()
{
    // 打开商店界面
}

void GameScreen::on_exitButton_clicked()
{
    // 退出游戏
}

void GameScreen::onGemClicked(int row, int col)
{
    if (selectedGem.isNull()) {
        selectedGem = QPoint(row, col);  // 第一次点击选择宝石
    } else {
        gameEngine->swapGems(selectedGem.x(), selectedGem.y(), row, col);  // 第二次点击交换宝石
        selectedGem = QPoint();  // 清空选择
    }
}
void GameScreen::pauseGame()
{
    isPaused = !isPaused; // 切换暂停状态
    if (isPaused) {
        timer->stop(); // 暂停定时器
        // 禁用宝石按钮的点击事件
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                buttons[row][col]->setEnabled(false);
            }
        }
        ui->pauseButton->setText("Resume"); // 更改按钮文本为 "Resume"
    } else {
        timer->start(10); // 恢复定时器
        // 启用宝石按钮的点击事件
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                buttons[row][col]->setEnabled(true);
            }
        }
        ui->pauseButton->setText("Pause"); // 更改按钮文本为 "Pause"
    }
}
void GameScreen::startCountdown()
{
    // 初始化倒计时条
    progressBar->setRange(0, 3000);  // 设置进度条范围为0到30秒
    progressBar->setValue(3000);  // 初始化为满
    updateTimeLabel(); // 更新时间标签
    timer->start(10);  // 每10毫秒（1秒）触发一次
}
void GameScreen::updateProgressBar()
{
    if (!isPaused &&progressBar->value() > 0) {
        int currentValue = progressBar->value() - 1;  // 每10毫秒减少1
        progressBar->setValue(currentValue);
        timeLeft = static_cast<int>(progressBar->value() / 100);  // 更新剩余时间
    } else if (progressBar->value() <= 0){
        timer->stop();
        timeLabel->setText("Time's up!");
        int currentScore = gameEngine->getScore(); // 获取当前分数
        endGame(currentScore); // 调用结束游戏的方法
    }
}
void GameScreen::updateTimeLabel()
{
    if (!isPaused &&timeLeft > 0) {
        timeLabel->setText(QString("%1 s").arg(timeLeft));
    } else if (timeLeft <= 0){
        timeLabel->setText("Time's up!");
        // 可以在这里添加游戏结束的逻辑
    }
}
void GameScreen::endGame(int score)
{
    QMessageBox::StandardButton button = QMessageBox::information(
        this, "Game Over",
        "您的分数为：" + QString::number(score) + "\n点击OK返回登录界面，点击关闭将封住方块。",
        QMessageBox::Ok | QMessageBox::Close,
        QMessageBox::Ok);
    if (button == QMessageBox::Ok) {
        on_gameOverDialogAccepted(); // 用户点击OK
    } else {
        on_gameOverDialogRejected(); // 用户点击关闭
    }
}
void GameScreen::on_gameOverDialogAccepted()
{
    emit returnToLogin(); // 发出返回登录界面信号
}
void GameScreen::on_gameOverDialogRejected()
{
    // 禁用宝石按钮的点击事件
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            buttons[row][col]->setEnabled(false);
        }
    }
    emit gameEnded(gameEngine->getScore()); // 发出游戏结束信号
}

//重置方法，将图上所有方块收集在一起，再按照行和列，一个一个像发牌的动画一样，将宝石送到新的位置，一个一个来送的
void GameScreen::on_resetButton_clicked()
{
    // 停止计时器和进度条，暂停游戏
    timer->stop();
    progressBar->setValue(3000);  // 重置进度条
    timeLeft = 30;  // 重置倒计时时间
    updateTimeLabel();  // 更新时间标签

    // 创建并行动画组
    QParallelAnimationGroup *animationGroup = new QParallelAnimationGroup(this);

    // 清空宝石并记录初始位置
    QVector<QPoint> initialPositions;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QPushButton *button = buttons[row][col];
            initialPositions.append(button->pos());

            // 将宝石移到屏幕中心
            QPropertyAnimation *moveAnimation = new QPropertyAnimation(button, "pos");
            moveAnimation->setDuration(500);
            moveAnimation->setStartValue(button->pos());
            moveAnimation->setEndValue(QPoint(410, 240));

            animationGroup->addAnimation(moveAnimation);
        }
    }

    // 启动动画
    animationGroup->start(QAbstractAnimation::DeleteWhenStopped);

    // 动画完成后发牌到新位置
    connect(animationGroup, &QParallelAnimationGroup::finished, this, &GameScreen::redealToGrid);
}
void GameScreen::redealToGrid()
{
    // 打乱宝石顺序
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::vector<QPushButton*> allButtons;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            allButtons.push_back(buttons[row][col]);
        }
    }
    std::shuffle(allButtons.begin(), allButtons.end(), rng);

    // 创建顺序动画组，发牌到新的位置
    QSequentialAnimationGroup *redealGroup = new QSequentialAnimationGroup(this);

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QPushButton *button = buttons[row][col];
            updateGemImage(button, row, col);  // 更新宝石图像

            // 目标位置
            QPoint targetPos(col * 60 + 10, row * 60 + 10);

            // 动画：将宝石移到新的位置
            QPropertyAnimation *moveAnimation = new QPropertyAnimation(button, "pos");
            moveAnimation->setDuration(100);
            moveAnimation->setStartValue(QPoint(410, 240));  // 从屏幕中心出发
            moveAnimation->setEndValue(targetPos);  // 到达目标位置

            redealGroup->addAnimation(moveAnimation);
        }
    }

    // 启动重新发牌的动画
    connect(redealGroup, &QSequentialAnimationGroup::finished, this, &GameScreen::resetBoard);
    redealGroup->start(QAbstractAnimation::DeleteWhenStopped);
}
void GameScreen::resetBoard()
{
    // 在所有动画完成后，统一更新宝石图像
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            updateGemImage(buttons[row][col], row, col);  // 更新宝石的图像
        }
    }

    // 恢复游戏状态
    gameEngine->startGame();  // 重启游戏引擎

    // 恢复倒计时和进度条
    progressBar->setValue(3000);  // 重置进度条
    timeLeft = 30;  // 重置倒计时时间
    updateTimeLabel();  // 更新时间标签
    timer->start(10);  // 启动定时器

    // 恢复暂停状态
    isPaused = false;
    ui->pauseButton->setText("Pause");  // 恢复按钮文本为 "Pause"

    // 启用宝石按钮的点击事件
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            buttons[row][col]->setEnabled(true);
        }
    }
}
void GameScreen::on_resetPotionPurchased(int count) {
    // 更新重置药水的数量
    resetPotionCount += count;

    // 输出重置药水的数量
    qDebug() << "重置药水数量: " << resetPotionCount;

    updateSkillLabel();  // 更新显示技能数量
}

void GameScreen::on_freezePotionPurchased(int count) {
    // 更新冷冻药水的数量
    freezePotionCount += count;

    // 输出冷冻药水的数量
    qDebug() << "冷冻药水数量: " << freezePotionCount;

    updateSkillLabel();  // 更新显示技能数量
}

void GameScreen::on_superPotionPurchased(int count) {
    // 更新超级药水的数量
    superPotionCount += count;

    // 输出超级药水的数量
    qDebug() << "超级药水数量: " << superPotionCount;

    updateSkillLabel();  // 更新显示技能数量
}
void GameScreen::updateSkillLabel() {
    skillLabel->setText(QString("药水数量: \n重置药水: %1, \n冷冻药水: %2, \n超级药水: %3")
                            .arg(resetPotionCount)
                            .arg(freezePotionCount)
                            .arg(superPotionCount));
}
