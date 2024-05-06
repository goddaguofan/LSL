#ifndef RANKPAGE_H
#define RANKPAGE_H

#include <QWidget>
#include <QDebug>
#include "playermanager.h"

namespace Ui {
class RankPage;
}

class RankPage : public QWidget
{
    Q_OBJECT

public:
    explicit RankPage(QWidget *parent = nullptr);
    ~RankPage();
    void showEvent(QShowEvent *event);
    void rankWithAverageScore();
    void rankWithWinningProbability();

private slots:
    void on_averageScoreBtn_clicked();

    void on_winningProbabilityBtn_clicked();

private:
    void initRankPage();
    void clearRankList();
    void insertDataToRankList(QList<Player> list);
    Ui::RankPage *ui;
    PlayerManager playerManager;
    QList<Player> playerList;
};

#endif // RANKPAGE_H
