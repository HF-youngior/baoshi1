#include "startscreen.h"
#include "ui_startscreen.h"
#include "gamescreen.h"
#include "databasemanager.h"
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

StartScreen::StartScreen(const QString &userEmail, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartScreen)
    , userEmail(userEmail)  // 保存传入的邮箱

{
    ui->setupUi(this);
    // 设置整个页面大小
    this->setFixedSize(900, 650);

    // 一开始隐藏frame
    ui->frame->hide();

    // 获取并显示当前玩家的余额（分数）
    loadUserBalance();
}

StartScreen::~StartScreen()
{
    delete ui;
}

// StartScreen.cpp
void StartScreen::on_pushButton_2_clicked()
{
    // 初始化 GameScreen 对象
    gameScreen = new GameScreen(userEmail);
    emit startGameSignal(); // 发射信号开始游戏
    gameScreen->startCountdown();  // 调用 startCountdown 开始倒计时
    connect(gameScreen, &GameScreen::gameEnded, this, &StartScreen::on_gameEnded);
    connect(gameScreen, &GameScreen::returnToLogin, this, &StartScreen::on_returnToLogin);

    // 打开游戏界面
    gameScreen->show();  // 显示游戏界面
    this->hide();        // 隐藏主窗口（可以选择是否隐藏主窗口）
}

void StartScreen::on_gameEnded()
{
    // 这里可以添加更新排行榜或其他逻辑
    // ...
}

void StartScreen::on_returnToLogin()
{
    this->show(); // 显示登录窗口
    if (gameScreen) {
        gameScreen->close(); // 关闭游戏窗口
    }
}

// 加载用户余额（分数）并显示到 label_4
void StartScreen::loadUserBalance()
{
    DatabaseManager dbManager;
    QString name;
    int score = 0;

    qDebug() << "Trying to load data for user:" << userEmail;

    if (dbManager.loadUserData(userEmail, name, score)) {
        // 显示分数作为余额
        ui->label_4->setText(QString("余额：%1").arg(score));
    } else {
        qDebug() << "Failed to load user data for email:" << userEmail;
    }
}

// 购买重置药水，价格为 20 分
void StartScreen::on_toolButton_3_clicked()
{
    // 检查是否有足够的余额（分数）
    DatabaseManager dbManager;
    QString name;
    int score = 0;

    if (dbManager.loadUserData(userEmail, name, score)) {
        if (score >= 20) {
            // 扣除分数并更新数据库
            score -= 20;
            dbManager.saveUserData(name, userEmail, score);

            // 更新 UI 中的余额
            ui->label_4->setText(QString("余额：%1").arg(score));

            // 发射信号：购买了 1 瓶重置药水
            emit resetPotionPurchased(1);

            qDebug() << "You have purchased a Reset Potion!";
        } else {
            // 显示提示余额不足
            qDebug() << "Not enough balance to purchase Reset Potion.";
        }
    } else {
        qDebug() << "Failed to load user data.";
    }
}
// 购买冷冻药水，价格为 10 分

void StartScreen::on_toolButton_4_clicked()
{
    // 检查是否有足够的余额（分数）
    DatabaseManager dbManager;
    QString name;
    int score = 0;

    if (dbManager.loadUserData(userEmail, name, score)) {
        if (score >= 10) {
            // 扣除分数并更新数据库
            score -= 10;
            dbManager.saveUserData(name, userEmail, score);

            // 更新 UI 中的余额
            ui->label_4->setText(QString("余额：%1").arg(score));

            // 发射信号：购买了 1 瓶冷冻药水
            emit freezePotionPurchased(1);

            qDebug() << "You have purchased a Freeze Potion!";
        } else {
            // 显示提示余额不足
            qDebug() << "Not enough balance to purchase Freeze Potion.";
        }
    } else {
        qDebug() << "Failed to load user data.";
    }
}
// 购买超级药水，价格为 30 分
void StartScreen::on_toolButton_5_clicked()
{
    // 检查是否有足够的余额（分数）
    DatabaseManager dbManager;
    QString name;
    int score = 0;

    if (dbManager.loadUserData(userEmail, name, score)) {
        if (score >= 30) {
            // 扣除分数并更新数据库
            score -= 30;
            dbManager.saveUserData(name, userEmail, score);

            // 更新 UI 中的余额
            ui->label_4->setText(QString("余额：%1").arg(score));

            // 发射信号：购买了 1 瓶超级药水
            emit superPotionPurchased(1);

            qDebug() << "You have purchased a Super Potion!";
        } else {
            // 显示提示余额不足
            qDebug() << "Not enough balance to purchase Super Potion.";
        }
    } else {
        qDebug() << "Failed to load user data.";
    }
}
