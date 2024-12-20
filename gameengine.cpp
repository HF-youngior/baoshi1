/**
 * GameEngine(游戏引擎类）：游戏运行的主要逻辑。
 * startGame()：启动游戏
 * randomGemType()：随机宝石类型
 * getGemAt(int row, int col)：获取宝石位置
 * swapGems(int row1, int col1, int row2, int col2)：交换宝石位置，“检查是否匹配”与“动画显示”不同时进行
 * matchGems()：匹配宝石并准备消除
 * checkMatch(int row, int col)：确顶横向与纵向的已匹配的三个及以上的宝石
 * clearMatchedGems(int row, int col)：清除已匹配的宝石，重复操作直至地图中没有匹配三个及以上宝石
 * handleGemFalling()：向下掉落宝石填补形成宝石迷阵新地图
 * updateBoardWithAnimation()：使用动画更新宝石迷阵地图
 * updateScore(int points)：更新分数并显示
 */
#include "GameEngine.h"
#include "databasemanager.h"  // 引入数据库管理类
#include <QRandomGenerator>
#include <QTimer>
#include <QDebug>

GameEngine::GameEngine(const QString &userEmail, QObject *parent)
    : QObject(parent),
    userEmail(userEmail),  // 使用传入的 userEmail 参数进行初始化
    score(0),
    m_timer(new QTimer(this)),
    m_currentStep(Step::None),
    m_swapProgress(0),  // 交换动画进度
    m_swapCount(0) // 交换计数器
{
    // 初始化宝石矩阵
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            board[row][col] = randomGemType();
        }
    }

    // 设置定时器，用于动画效果
    connect(m_timer, &QTimer::timeout, this, &GameEngine::updateBoardWithAnimation);
    m_timer->setInterval(100);  // 每次动画帧间隔100毫秒

}

GameEngine::~GameEngine() {}

void GameEngine::startGame()
{
    score = 0;
    emit updateBoard();  // 初始更新UI
}

QString GameEngine::randomGemType()
{
    QStringList gemTypes = {"Gem1", "Gem2", "Gem3", "Gem4"};
    return gemTypes[QRandomGenerator::global()->bounded(4)];
}

QString GameEngine::getGemAt(int row, int col)
{
    return board[row][col];
}
void GameEngine::swapGems(int row1, int col1, int row2, int col2)
{
    // 记录第一次交换的位置
    m_row1 = row1;
    m_col1 = col1;
    m_row2 = row2;
    m_col2 = col2;

    // 交换宝石
    QString temp = board[row1][col1];
    board[row1][col1] = board[row2][col2];
    board[row2][col2] = temp;

    // 启动交换动画
    m_currentStep = Step::Swap;
    m_swapProgress = 0;
    m_swapCount = 0;  // 确保交换计数器为 0
    m_timer->start();
}

bool GameEngine::matchGems()
{
    bool matched = false;

    do {
        matched = false;
        // 检查并消除行或列上的匹配宝石
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (checkMatch(row, col)) {
                    clearMatchedGems(row, col);
                    matched = true;
                }
            }
        }

        // 如果有消除，处理宝石下落
        if (matched) {
            handleGemFalling();

        }

    } while (matched);  // 如果消除了匹配的宝石，继续检查是否有新的匹配

    return matched;
}

bool GameEngine::checkMatch(int row, int col)
{
    // 横向匹配检查
    if (col + 2 < 8 && board[row][col] == board[row][col + 1] && board[row][col] == board[row][col + 2]) {
        return true;
    }
    // 纵向匹配检查
    if (row + 2 < 8 && board[row][col] == board[row + 1][col] && board[row][col] == board[row + 2][col]) {
        return true;
    }
    return false;
}

void GameEngine::clearMatchedGems(int row, int col)
{
    QString gem = board[row][col];
    QVector<QPair<int, int>> matchedGems;
    matchedGems.append(qMakePair(row, col));  // 当前宝石加入匹配列表

    // 横向检查
    for (int i = col + 1; i < 8 && board[row][i] == gem; ++i) {
        matchedGems.append(qMakePair(row, i));
    }
    if (matchedGems.size() >= 3) {
        for (auto &gemPos : matchedGems) {
            board[gemPos.first][gemPos.second] = "Empty";
        }
        updateScore(matchedGems.size() * 1);
    }

    matchedGems.clear();

    // 纵向检查
    matchedGems.append(qMakePair(row, col));

    for (int i = row + 1; i < 8 && board[i][col] == gem; ++i) {
        matchedGems.append(qMakePair(i, col));
    }
    if (matchedGems.size() >= 3) {
        for (auto &gemPos : matchedGems) {
            board[gemPos.first][gemPos.second] = "Empty";
        }
        updateScore(matchedGems.size() * 1);
    }
}

void GameEngine::handleGemFalling()
{
    // 向下掉落的算法，处理空位
    for (int col = 0; col < 8; ++col) {
        for (int row = 7; row >= 0; --row) {
            if (board[row][col] == "Empty") {
                for (int above = row - 1; above >= 0; --above) {
                    if (board[above][col] != "Empty") {
                        board[row][col] = board[above][col];
                        board[above][col] = "Empty";
                        break;
                    }
                }
            }
        }
    }

    // 生成新的宝石填充空位
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col] == "Empty") {
                board[row][col] = randomGemType();
            }
        }
    }

    // 更新UI显示
    emit updateBoard();
}

void GameEngine::updateBoardWithAnimation()
{
    bool matched = false;  // 将变量定义移到函数开始

    switch (m_currentStep) {
    case Step::Swap:
        m_swapProgress += 10;  // 每次增加10%的动画进度
        if (m_swapProgress >= 100) {
            // 交换完成，检查是否有匹配
            matched = matchGems();  // 在这里调用 matchGems
            if (matched) {
                // 如果匹配，执行消除操作
                m_currentStep = Step::Clear;
            } else {
                // 如果没有匹配，撤销交换
                QString temp = board[m_row1][m_col1];
                board[m_row1][m_col1] = board[m_row2][m_col2];
                board[m_row2][m_col2] = temp;

                // 只进行一次撤销交换，不再递归
                m_swapCount++;

                if (m_swapCount >= 1) {
                    // 已经撤销过交换，停止动画
                    m_currentStep = Step::None;
                    m_swapCount = 0;
                    m_timer->stop();
                    emit updateBoard();  // 更新UI
                }
            }
        }
        break;

    case Step::Clear:
        matched = matchGems();  // 执行消除操作
        m_currentStep = Step::Fall;  // 切换到掉落步骤
        break;

    case Step::Fall:
        handleGemFalling();  // 执行掉落操作
        // 生成新宝石后，检查并消除匹配
        matched = matchGems();
        if (matched) {
            // 如果有匹配，执行消除操作并继续下落
            m_currentStep = Step::Clear;
        } else {
            m_currentStep = Step::None;  // 没有匹配，结束动画
        }

        m_currentStep = Step::Generate;  // 切换到生成步骤
        break;

    case Step::Generate:
        // 生成新的宝石填充空位
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col] == "Empty") {
                    board[row][col] = randomGemType();
                }
            }
        }

        // 生成新宝石后，检查并消除匹配
        matched = matchGems();
        if (matched) {
            // 如果有匹配，执行消除操作并继续下落
            m_currentStep = Step::Clear;
        } else {
            m_currentStep = Step::None;  // 没有匹配，结束动画
        }

        m_timer->stop();  // 停止定时器
        emit updateBoard();  // 完成动画，更新UI
        break;

    case Step::None:
        return;
    }

    emit updateBoard();  // 每个步骤后更新UI
}
void GameEngine::updateScore(int points)
{
    score += points;  // 更新游戏内的分数
    qDebug() << "当前分数: " << score;
    emit scoreChanged(score);  // 更新 UI 中的分数

    // 获取当前用户的分数并更新数据库
    DatabaseManager dbManager;
    QString userName;
    int dbScore = 0;
    // 打印调试信息
    qDebug() << "User Email2: " << userEmail;
    if (dbManager.loadUserData(userEmail, userName, dbScore)) {
        // 比较数据库中的分数与游戏中的分数，取最大值
        int finalScore = qMax(score, dbScore);

        // 更新数据库中的分数
        if (dbManager.saveUserData(userName, userEmail, finalScore)) {
            qDebug() << "分数更新成功！";
        } else {
            qDebug() << "分数更新失败！";
        }
    } else {
        qDebug() << "无法加载用户数据！";
    }
}
int GameEngine::getScore()
{
    return score;
}
