/**
 * LoginScreen（初始页面类）：初始登录或注册用户的界面
 * on_login_clicked()：单击以输入用户的用户名与邮箱信息
 * on_gameButton_clicked()：单击可开始游戏
 * on_rankinglistButton_clicked()：单击以打开排行榜
 */
#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "rankinglist.h"
#include <QMessageBox>
#include "startscreen.h"

LoginScreen::LoginScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    // 连接数据库
    if (!dbManager.connect()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
    }

    // 初始化时禁用开始游戏按钮
    ui->gameButton->setEnabled(false);  // 禁用游戏按钮
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_login_clicked()
{
    QString name = ui->nameLineEdit->text();  // 获取用户输入的名字
    userEmail = ui->emailLineEdit->text();  // 获取用户输入的邮箱

    if (name.isEmpty() || userEmail.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both name and email.");
        return;
    }

    // 检查用户是否已经存在
    QString existingName;
    int existingScore;
    if (dbManager.loadUserData(userEmail, existingName, existingScore)) {
        // 用户已存在，提示登录成功并显示分数
        QMessageBox::information(this, "Login Success", "Welcome back, " + existingName + "!\nYour score: " + QString::number(existingScore));
    } else {
        // 用户不存在，创建新用户
        if (dbManager.saveUserData(name, userEmail, 0)) {
            QMessageBox::information(this, "Registration Success", "New user registered successfully!");
        } else {
            QMessageBox::critical(this, "Error", "Failed to register new user.");
            return; // 如果注册失败，不允许启用游戏按钮
        }
    }

    // 登录或注册成功后，启用游戏按钮
    ui->gameButton->setEnabled(true);
}

// 点击开始游戏
void LoginScreen::on_gameButton_clicked()
{
    // 初始化 GameScreen 对象时传递邮箱
    startScreen = new StartScreen(userEmail);
    // 打开游戏界面
    startScreen->show();  // 显示游戏界面
    this->hide();        // 隐藏主窗口（可以选择是否隐藏主窗口）

}
//点击展开排行榜
void LoginScreen::on_rankinglistButton_clicked()
{
    rankingList = new RankingList();
    rankingList->show();

    // 排行榜按钮事件
}
