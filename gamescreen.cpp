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
#include "gamescreen.h"
#include "ui_gamescreen.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QFont>

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
        timer->stop();  // 停止定时器
        // 可以在这里添加游戏结束的逻辑
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
