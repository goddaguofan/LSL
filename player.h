#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "gamedata.h"

class Player
{
public:
    Player(QString name);
    void addGameData(GameData gameData);

    QString getPlayerName() {return playerName;};
    QList<GameData> getGameList() {return gameList;};
    double getAverageScore() {return averageScore;};
    double getWinningProbability() {return winningProbability;};
private:
    QString playerName;
    QList<GameData> gameList;
    double averageScore = 0.0;
    double winningProbability = 0.0;
};

#endif // PLAYER_H
