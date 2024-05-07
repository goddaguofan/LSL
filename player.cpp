#include "player.h"
#include <QDebug>

Player::Player(QString name)
{
    playerName = name;
}

void Player::addGameData(GameData gameData)
{
    gameList.append(gameData);

    //刷新均分和胜率
    double totalScore = 0.0;
    int winGames = 0;
    foreach(GameData game,gameList){
        totalScore += game.score;
        if(game.isWin) winGames++;
    }
    averageScore = totalScore/gameList.size();
    winningProbability = static_cast<double>(winGames)/static_cast<double>(gameList.size());
}
