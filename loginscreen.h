#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QWidget>
#include "databasemanager.h"  // 引入数据库管理类
#include "startscreen.h"    // 引入游戏界面类
#include "rankinglist.h"

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QWidget
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();
    QString userEmail;            // 当前登录用户的邮箱
signals:
    void startGameSignal(); // 添加一个信号

private slots:
    void on_login_clicked();
    void on_gameButton_clicked();
    void on_rankinglistButton_clicked();

private:
    Ui::LoginScreen *ui;
    DatabaseManager dbManager;    // 数据库管理对象
    StartScreen *startScreen;;       // 游戏界面对象
    RankingList *rankingList;

};

#endif // LOGINSCREEN_H
