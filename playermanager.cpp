#include "playermanager.h"

PlayerManager::PlayerManager(QObject *parent) : QObject(parent)
{
    playerList = dataFile.getPlayerList();
}

bool PlayerManager::addNewPlayer(QString playerName)
{
    for(int i=0;i<playerList.size();i++){
        if(playerList[i].getPlayerName() == playerName){
            qDebug()<<"PlayerManager::addNewPlayer - Player is exists";
            return false;
        }
    }
    Player newPlayer(playerName);
    playerList.append(newPlayer);
    saveDateToFile();
    return true;
}

void PlayerManager::addNewGameData(QList<QString> playerDataList, QList<GameData> gameDataList)
{
    for(int i=0;i<playerDataList.size();i++){
        for(int j=0;j<playerList.size();j++){
            if(playerDataList[i] == playerList[j].getPlayerName()){
                playerList[j].addGameData(gameDataList[i]);
            }
        }
    }
    saveDateToFile();
}

void PlayerManager::saveDateToFile()
{
    dataFile.updatePlayerList(playerList);
}

QList<Player> PlayerManager::getPlayerListWithAverageScore(QList<Player> list)
{
    qSort(list.begin(), list.end(), [](Player & a, Player & b) {
        return a.getAverageScore() > b.getAverageScore();
    });
    return list ;
}

QList<Player> PlayerManager::getPlayerListWithWinningPercentage(QList<Player> list)
{
    qSort(list.begin(), list.end(), [](Player & a, Player & b) {
        return a.getWinningProbability() > b.getWinningProbability();
    });
    return list ;
}
