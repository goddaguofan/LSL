#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <QObject>

class GameData
{
public:
    QString gameName;
    QString gameTime;
    double score;
    bool isWin;
    bool isSup;
};

#endif // GAMEDATA_H
