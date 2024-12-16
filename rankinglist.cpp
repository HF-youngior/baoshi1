#include "rankinglist.h"
#include "ui_rankinglist.h"
#include "databasemanager.h"

RankingList::RankingList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RankingList)
{
    ui->setupUi(this);

    // 获取排名并显示
    displayRanking();
}

RankingList::~RankingList()
{
    delete ui;
}

void RankingList::displayRanking()
{
    DatabaseManager dbManager;
    if (!dbManager.connect()) {
        qDebug() << "Database connection failed!";
        return;
    }

    QList<DatabaseManager::User> rankingList;  // 使用DatabaseManager::User
    if (dbManager.getRankingList(rankingList)) {
        // 设置表格的行数和列数
        ui->rankingTableWidget->setRowCount(rankingList.size());
        ui->rankingTableWidget->setColumnCount(4);  // 排名、名字、邮箱、分数

        // 设置表头
        ui->rankingTableWidget->setHorizontalHeaderLabels(QStringList() << "Rank" << "Name" << "Email" << "Score");

        // 填充表格数据
        for (int i = 0; i < rankingList.size(); ++i) {
            const DatabaseManager::User &user = rankingList[i];  // 使用DatabaseManager::User

            // 排名从 1 开始
            ui->rankingTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
            ui->rankingTableWidget->setItem(i, 1, new QTableWidgetItem(user.name));
            ui->rankingTableWidget->setItem(i, 2, new QTableWidgetItem(user.email));
            ui->rankingTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(user.score)));
        }
    } else {
        qDebug() << "Failed to load ranking list.";
    }
}

void RankingList::on_back_clicked()
{
    this->close();
}
