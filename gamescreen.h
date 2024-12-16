#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QWidget>
#include <QPoint>
#include <QPushButton>
#include <QProgressBar>
#include <QGridLayout>
#include <QPixmap>
#include "GameEngine.h"
#include "ui_gamescreen.h"

namespace Ui {
class GameScreen;
}

class GameScreen : public QWidget
{
    Q_OBJECT

public:
    explicit GameScreen(const QString &userEmail, QWidget *parent = nullptr);
    ~GameScreen();
public slots:
    void startCountdown(); // 添加一个公共槽函数
    void pauseGame(); // 新增暂停槽函数
private:
    Ui::GameScreen *ui;

    // 用于存储宝石按钮的二维数组
    QPushButton *buttons[8][8];  // 8x8矩阵的宝石按钮数组

    // 用于记录已选择的宝石位置
    QPoint selectedGem;

    // 游戏引擎实例
    class GameEngine *gameEngine;

    // 初始化游戏棋盘
    void initBoard();

    // 更新宝石图片
    void updateGemImage(QPushButton *button, int row, int col);

    // 更新整个棋盘
    void updateBoard();
    void updateScore(int newScore);
    QLabel *scoreLabel;  // 声明 QLabel，用于显示分数
    QString userEmail;  // 当前用户的邮箱
    // 更新进度条
    void updateProgressBar();

    // 更新时间标签的函数
    void updateTimeLabel();

    // 新增暂停标志
    bool isPaused;

    QPushButton *pauseButton; // 暂停按钮
    QProgressBar *progressBar; // 声明QProgressBar,用于显示倒计时
    QLabel *timeLabel; // 用于显示剩余时间的 QLabel
    int timeLeft;  // 剩余时间
    QTimer *timer;  // 定时器


private slots:
    // 商店按钮点击
    void on_shopButton_clicked();

    // 退出按钮点击
    void on_exitButton_clicked();

    // 宝石点击事件
    void onGemClicked(int row, int col);

};

#endif // GAMESCREEN_H
