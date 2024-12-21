#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>
#include "gamescreen.h"     // 引入游戏界面类

namespace Ui {
class StartScreen;
}

class StartScreen : public QWidget
{
    Q_OBJECT

public:
    // 构造函数，接收一个邮箱参数
    explicit StartScreen(const QString &userEmail, QWidget *parent = nullptr);
    ~StartScreen();
signals:

    void startGameSignal(); // 添加一个信号
    void resetPotionPurchased(int count);  // 发射购买重置药水的信号
    void freezePotionPurchased(int count); // 发射购买冷冻药水的信号
    void superPotionPurchased(int count);  // 发射购买超级药水的信号
private slots:
    void on_pushButton_2_clicked();
    void on_gameEnded(); // 新增槽函数，处理游戏结束逻辑
    void on_returnToLogin(); // 新增槽函数，处理返回登录界面逻辑

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

private:
    Ui::StartScreen *ui;             // UI对象
    GameScreen *gameScreen;          // 游戏屏幕对象
    QString userEmail;               // 当前用户的邮箱

    // 加载用户余额并显示到 label_4
    void loadUserBalance();
};

#endif // STARTSCREEN_H
