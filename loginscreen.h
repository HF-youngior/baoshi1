#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QWidget>
#include "databasemanager.h"  // 引入数据库管理类
#include "gamescreen.h"       // 引入游戏界面类

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QWidget
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private slots:
    void on_login_clicked();
    void on_gameButton_clicked();
    void on_rankinglistButton_clicked();

private:
    Ui::LoginScreen *ui;
    DatabaseManager dbManager;    // 数据库管理对象
    GameScreen *gameScreen;       // 游戏界面对象
    QString userEmail;            // 当前登录用户的邮箱
};

#endif // LOGINSCREEN_H
