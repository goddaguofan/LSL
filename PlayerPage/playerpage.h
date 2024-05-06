#ifndef PLAYERPAGE_H
#define PLAYERPAGE_H

#include <QWidget>
#include <QDebug>
#include "playermanager.h"

namespace Ui {
class PlayerPage;
}

class PlayerPage : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerPage(QWidget *parent = nullptr);
    ~PlayerPage();
    void showEvent(QShowEvent *event);

private slots:
    void on_addNewPlayerBtn_clicked();

    void on_newPlayer_returnPressed();

private:
    void initPlayerPage();
    Ui::PlayerPage *ui;
    PlayerManager playerManager;
    QList<Player> playerList;
};

#endif // PLAYERPAGE_H
