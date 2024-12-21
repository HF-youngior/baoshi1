#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QWidget>
#include <QPoint>
#include <QPushButton>
#include <QProgressBar>
#include <QGridLayout>
#include <QPixmap>
#include "GameEngine.h"  // 保持对 GameEngine.h 的引用

#include "ui_gamescreen.h" // 在最后包含 Ui::GameScreen
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
    void endGame(int score); // 新增槽函数，处理游戏结束逻辑

signals:
    void gameEnded(int score); // 新增信号，用于通知游戏结束和分数
    void returnToLogin(); // 新增信号，返回登录界面

    void resetPotionPurchased(int count);  // 信号: 重置药水购买
    void freezePotionPurchased(int count); // 信号: 冷冻药水购买
    void superPotionPurchased(int count);  // 信号: 超级药水购买

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

    int resetPotionCount;        // 重置药水数量
    int freezePotionCount;       // 冷冻药水数量
    int superPotionCount;        // 超级药水数量
    QLabel *skillLabel;          // 显示技能（药水）数量
    void updateSkillLabel();     // 更新技能标签


private slots:
    // 商店按钮点击
    void on_shopButton_clicked();

    // 退出按钮点击
    void on_exitButton_clicked();

    // 宝石点击事件
    void onGemClicked(int row, int col);

    void on_resetButton_clicked();
    void resetBoard();

    void redealToGrid();
    void on_gameOverDialogAccepted(); // 新增槽函数，当用户点击OK时调用
    void on_gameOverDialogRejected(); // 新增槽函数，当用户点击关闭时调用

    void on_resetPotionPurchased(int count);  // 接收购买重置药水的信号
    void on_freezePotionPurchased(int count); // 接收购买冷冻药水的信号
    void on_superPotionPurchased(int count);  // 接收购买超级药水的信号
};

#endif // GAMESCREEN_H
