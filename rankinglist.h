#ifndef RANKINGLIST_H
#define RANKINGLIST_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QList>

namespace Ui {
class RankingList;
}

class RankingList : public QWidget
{
    Q_OBJECT

public:
    explicit RankingList(QWidget *parent = nullptr);
    ~RankingList();

private slots:
    void on_back_clicked();  // 返回按钮槽函数

private:
    void displayRanking();  // 显示排行榜数据

    Ui::RankingList *ui;  // UI对象指针
};

struct User {
    QString name;  // 用户名字
    QString email;  // 用户邮箱
    int score;  // 用户分数
};

#endif // RANKINGLIST_H
