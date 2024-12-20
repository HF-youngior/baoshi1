/**
 * MainWindow(主函数界面类)
 * on_startGameButton_clicked()：单击开始游戏按钮后的操作
 * on_loginButton_clicked()：单击登录或注册后的操作
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamescreen.h"
#include "loginscreen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  // 设置主窗口的UI界面



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startGameButton_clicked()
{
    // 初始化GameScreen对象
    gameScreen = new GameScreen("12");
    emit startGameSignal(); // 发射信号开始游戏
    gameScreen->startCountdown();  // 调用 startCountdown 开始倒计时

    // 打开游戏界面
    gameScreen->show();  // 显示游戏界面
    this->hide();        // 隐藏主窗口（可以选择是否隐藏主窗口）
}


void MainWindow::on_loginButton_clicked()
{
    loginScreen = new LoginScreen();
    loginScreen->show();
    this->hide();

}

