#include "gamescreen.h"
#include "ui_gamescreen.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QFont>

GameScreen::GameScreen(const QString &userEmail, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameScreen)
    , userEmail(userEmail)  // 保存传入的邮箱
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