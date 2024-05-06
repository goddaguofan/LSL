#ifndef DATAFILE_H
#define DATAFILE_H

#include <QObject>
#include <QFile>
#include <QJsonObject>
#include <QJsonParseError>
#include "player.h"

class DataFile : public QObject
{
    Q_OBJECT
public:
    explicit DataFile(QObject *parent = nullptr);
    QList<Player> getPlayerList();
    void updatePlayerList(QList<Player> list);
signals:

private:
    void parseDataJson(QJsonObject jsonObj);
    void formatDataToJson(QList<Player> list);
    void saveJsonToFile(QJsonObject jsonObj);
    QString dataFile = "dataFile.json";
    QJsonObject dataJson;
    QList<Player> playerList;
};

#endif // DATAFILE_H
