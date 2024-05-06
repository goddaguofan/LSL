#ifndef ADDGAMEPAGE_H
#define ADDGAMEPAGE_H

#include <QWidget>
#include <QDebug>
#include "playermanager.h"

namespace Ui {
class AddGamePage;
}

class AddGamePage : public QWidget
{
    Q_OBJECT

public:
    explicit AddGamePage(QWidget *parent = nullptr);
    ~AddGamePage();
    void showEvent(QShowEvent *event);

private slots:
    void on_gameName_returnPressed();

    void on_gameTime_returnPressed();

    void on_saveGameBtn_clicked();

private:
    Ui::AddGamePage *ui;

private:
    bool checkData();
    void addGameData();
    void initPlayerList();
    PlayerManager playerManager;
    QList<Player> playerList;
};

#endif // ADDGAMEPAGE_H
