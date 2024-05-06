#include "datafile.h"
#include <QDebug>
DataFile::DataFile(QObject *parent) : QObject(parent)
{
    QFile file(dataFile);
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        return;
    }

    if (!jsonDoc.isObject()) {
        return;
    }

    dataJson.remove("");
    dataJson = jsonDoc.object();
    file.close();
    parseDataJson(dataJson);
}

void DataFile::parseDataJson(QJsonObject jsonObj)
{
    qDebug()<<"test-->jsonObj:"<<jsonObj;
    playerList.clear();
    for (auto it = jsonObj.constBegin(); it != jsonObj.constEnd(); ++it) {
        Player player(it.key());
        QJsonObject playerObj = it.value().toObject();
        for (auto itGame = playerObj.constBegin(); itGame != playerObj.constEnd(); ++itGame) {
            QString gameName = itGame.key();
            QJsonObject gameObj = itGame.value().toObject();
            GameData game;
            game.gameName = gameName;
            game.gameTime = gameObj.value("gameTime").toString();
            game.score = gameObj.value("score").toDouble();
            game.isWin = gameObj.value("isWin").toBool();
            game.isSup = gameObj.value("isSup").toBool();
            player.addGameData(game);
        }
        playerList.append(player);
       // qDebug()<<"test-->playerList:"<<playerList[0].getGameList()[0].score;
    }
}

void DataFile::formatDataToJson(QList<Player> list)
{
    QJsonObject jsonObj;
    for(int i = 0;i< list.size();i++){
        QJsonObject playerObject;
        QList<GameData> gameList = list[i].getGameList();
        for(int j=0; j< gameList.size();j++){
            QJsonObject gameObject;
            gameObject["time"] = gameList[j].gameTime;
            gameObject["score"] = gameList[j].score;
            gameObject["isWin"] = gameList[j].isWin;
            gameObject["isSup"] = gameList[j].isSup;
            playerObject[gameList[j].gameName] = gameObject;
        }
        jsonObj[list[i].getPlayerName()] = playerObject;
    }

    saveJsonToFile(jsonObj);
}

void DataFile::saveJsonToFile(QJsonObject jsonObj)
{
    QJsonDocument doc(jsonObj);
    QFile file(dataFile);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
}

QList<Player> DataFile::getPlayerList()
{
    return playerList;
}

void DataFile::updatePlayerList(QList<Player> list)
{
    playerList.clear();
    playerList = list;

    formatDataToJson(playerList);
}

