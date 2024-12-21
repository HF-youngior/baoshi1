/**
 * DatabaseManager（数据库管理类）：处理与数据库的交互
 * connect()：与本机数据库相连
 * saveUserData(const QString &name, const QString &email, int score)：保存注册或登录的用户信息
 * loadUserData(const QString &email, QString &name, int &score)：加载初始的数据库中内容
 * getRankingList(QList<User>& rankingList)：得到排行榜
 */
#include "databasemanager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariantList>


DatabaseManager::DatabaseManager() {}

bool DatabaseManager::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);  // 数据库主机地址
    db.setDatabaseName("baoshi1");
    db.setUserName("root");
    db.setPassword("asdfgh0625YYH");


    if (!db.open()) {
        qDebug() << "Database connection failed: " << db.lastError().text();
        return false;
    }
    qDebug() << "Database connected successfully!";
    return true;
}

bool DatabaseManager::saveUserData(const QString &name, const QString &email, int score)
{
    QSqlQuery query;
    // 检查用户是否已经存在
    query.prepare("SELECT * FROM users WHERE email = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        // 用户已存在，更新分数
        query.prepare("UPDATE users SET score = :score WHERE email = :email");
        query.bindValue(":score", score);
        query.bindValue(":email", email);
        if (query.exec()) {
            qDebug() << "Score updated successfully!";
            return true;
        } else {
            qDebug() << "Error updating score: " << query.lastError().text();
            return false;
        }
    } else {
        // 用户不存在，插入新用户
        query.prepare("INSERT INTO users (name, email, score) VALUES (:name, :email, :score)");
        query.bindValue(":name", name);
        query.bindValue(":email", email);
        query.bindValue(":score", score);
        if (query.exec()) {
            qDebug() << "New user registered successfully!";
            return true;
        } else {
            qDebug() << "Error saving user data: " << query.lastError().text();
            return false;
        }
    }
}

bool DatabaseManager::loadUserData(const QString &email, QString &name, int &score)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE email = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        if (query.next()) {
            name = query.value("name").toString();
            score = query.value("score").toInt();
            return true;  // 查询成功，返回用户数据
        } else {
            qDebug() << "No user found with email:" << email;
            return false;  // 没有找到用户
        }
    } else {
        qDebug() << "Database query failed:" << query.lastError().text();
        return false;  // 查询执行失败
    }
}


bool DatabaseManager::getRankingList(QList<User>& rankingList)
{
    QSqlQuery query;
    query.prepare("SELECT name, email, score FROM users ORDER BY score DESC");

    if (query.exec()) {
        while (query.next()) {
            QString name = query.value(0).toString();
            QString email = query.value(1).toString();
            int score = query.value(2).toInt();

            User user;
            user.name = name;
            user.email = email;
            user.score = score;
            rankingList.append(user);
        }
        return true;
    } else {
        qDebug() << "Error fetching ranking list: " << query.lastError().text();
        return false;
    }
}
