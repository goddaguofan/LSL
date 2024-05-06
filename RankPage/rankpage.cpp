#include "rankpage.h"
#include "ui_rankpage.h"

RankPage::RankPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankPage)
{
    ui->setupUi(this);
}

RankPage::~RankPage()
{
    delete ui;
}

void RankPage::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    qDebug()<<"RankPage init";
    playerList = playerManager.getPlayerList();
    initRankPage();
    ui->averageScoreBtn->click();
}

void RankPage::on_averageScoreBtn_clicked()
{
    rankWithAverageScore();
}

void RankPage::on_winningProbabilityBtn_clicked()
{
    rankWithWinningProbability();
}

void RankPage::rankWithAverageScore()
{
    clearRankList();
    QList<Player> list = playerManager.getPlayerListWithAverageScore(playerList);
    insertDataToRankList(list);
}

void RankPage::rankWithWinningProbability()
{
    clearRankList();
    QList<Player> list = playerManager.getPlayerListWithWinningPercentage(playerList);
    insertDataToRankList(list);
}

void RankPage::initRankPage()
{
    ui->rankList->verticalHeader()->hide();
    ui->rankList->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->rankList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->rankList->setColumnCount(4);
    QTableWidgetItem *item0 = new QTableWidgetItem;
    QTableWidgetItem *item1 = new QTableWidgetItem;
    QTableWidgetItem *item2 = new QTableWidgetItem;
    QTableWidgetItem *item3 = new QTableWidgetItem;
    item0->setText("排名");
    item1->setText("选手");
    item2->setText("场均");
    item3->setText("胜率");
    ui->rankList->setHorizontalHeaderItem(0,item0);
    ui->rankList->setHorizontalHeaderItem(1,item1);
    ui->rankList->setHorizontalHeaderItem(2,item2);
    ui->rankList->setHorizontalHeaderItem(3,item3);
}

void RankPage::clearRankList()
{
    for (int i = ui->rankList->rowCount() - 1; i >= 0; --i) {
        ui->rankList->removeRow(i);
    }
}

void RankPage::insertDataToRankList(QList<Player> list)
{
    qDebug()<<"test-->rowCount:"<<list.size();
    QList<Player> newList;
    for (int j = 0; j < list.size(); ++j) {
        if(list[j].getGameList().size() <= 0)
            continue;
        else
            newList.append(list[j]);
    }


    int rowCount = newList.size();
    ui->rankList->setRowCount(rowCount);
    if(rowCount <=0) return;
    for (int i = 0; i < rowCount; ++i) {
        QTableWidgetItem *rankData = new QTableWidgetItem;
        QTableWidgetItem *nameData = new QTableWidgetItem;
        QTableWidgetItem *scoreData = new QTableWidgetItem;
        QTableWidgetItem *winData = new QTableWidgetItem;
        // insert data
        rankData->setText(QString::number(i+1));
        nameData->setText(newList[i].getPlayerName());

        double socre = newList[i].getAverageScore();
        scoreData->setText(QString::number(socre, 'f', 2));

        double winPerc = newList[i].getWinningProbability();
        winData->setText(QString::number(winPerc * 100, 'f', 2) + "%");
        rankData->setTextAlignment(Qt::AlignCenter);
        nameData->setTextAlignment(Qt::AlignCenter);
        scoreData->setTextAlignment(Qt::AlignCenter);
        winData->setTextAlignment(Qt::AlignCenter);
        qDebug()<<"n:"<<QString::number(i+1) << "  name:"<<newList[i].getPlayerName();

        ui->rankList->setItem(i, 0, rankData);
        ui->rankList->setItem(i, 1, nameData);
        ui->rankList->setItem(i, 2, scoreData);
        ui->rankList->setItem(i, 3, winData);
    }
}
