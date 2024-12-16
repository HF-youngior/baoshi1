#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    DatabaseManager();
    bool connect();          // 连接数据库
    bool saveUserData(const QString &name, const QString &email, int score);  // 保存用户数据
    bool loadUserData(const QString &email, QString &name, int &score);  // 加载用户数据

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
