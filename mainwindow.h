#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamescreen.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void startGameSignal(); // 添加一个信号
private:
    Ui::MainWindow *ui;

    // 游戏界面对象
    class GameScreen *gameScreen;
    class LoginScreen *loginScreen;

private slots:
    // 打开游戏界面
    void on_startGameButton_clicked();
    void on_loginButton_clicked();
};

#endif // MAINWINDOW_H
