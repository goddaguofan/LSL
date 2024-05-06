#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <QObject>
#include <QDebug>
#include "player.h"
#include "datafile.h"

class PlayerManager : public QObject
{
    Q_OBJECT
public:
    explicit PlayerManager(QObject *parent = nullptr);
    QList<Player> getPlayerList() {return playerList;};
    bool addNewPlayer(QString playerName);
    void addNewGameData(QList<QString> playerDataList,QList<GameData> gameDataList);
    QList<Player> getPlayerListWithAverageScore(QList<Player> list);
    QList<Player> getPlayerListWithWinningPercentage(QList<Player> list);
signals:

private:
    void saveDateToFile();
    QList<Player> playerList;
    DataFile dataFile;
};

#endif // PLAYERMANAGER_H
