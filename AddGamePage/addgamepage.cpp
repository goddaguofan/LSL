#include "addgamepage.h"
#include "ui_addgamepage.h"
#include <QMessageBox>

AddGamePage::AddGamePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddGamePage)
{
    ui->setupUi(this);
}

AddGamePage::~AddGamePage()
{
    delete ui;
}

void AddGamePage::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    qDebug()<<"AddGamePage init";
    playerList.clear();
    playerList = playerManager.getPlayerList();

    initPlayerList();
}

void AddGamePage::on_gameName_returnPressed()
{
    return;
}

void AddGamePage::on_gameTime_returnPressed()
{
    return;
}

void AddGamePage::on_saveGameBtn_clicked()
{
    if(ui->gameName->text().isEmpty()){
        QMessageBox::critical(nullptr, "Error", QString::fromUtf8("对局名称为空!"));
        return;
    }
    if(ui->gameTime->text().isEmpty()){
        QMessageBox::critical(nullptr, "Error", QString::fromUtf8("对局时间为空!"));
        return;
    }
    if(!checkData()){
        return;
    }
    //添加对局数据
    addGameData();
    QMessageBox::information(nullptr, "Yes", QString::fromUtf8("对局已添加!"));
}

bool AddGamePage::checkData()
{
    QList<QString> list;
    for(int i=1;i<=10;i++){
        QString player = this->findChild<QComboBox *>("player_"+QString::number(i))->currentText();
        if(player.isEmpty()){
            QMessageBox::critical(nullptr, "Error", QString::fromUtf8("玩家为空!"));
            return false;
        }
        if (!list.contains(player)) {
            list.append(player);
        }else{
            QMessageBox::critical(nullptr, "Error", QString::fromUtf8("玩家重复!"));
            return false;
        }
    }
    return  true;
}

void AddGamePage::addGameData()
{
    QList<QString> playerNameList;
    QList<GameData> gameDataList;
    QString gameName = ui->gameName->text();
    QString gameTime = ui->gameTime->text();
    for(int i=1;i<=10;i++){
        QString player = this->findChild<QComboBox *>("player_"+QString::number(i))->currentText();
        double score = this->findChild<QDoubleSpinBox *>("score_"+QString::number(i))->value();
        bool isWin = this->findChild<QCheckBox *>("isWin_"+QString::number(i))->isChecked();
        bool isSup = this->findChild<QCheckBox *>("isSup_"+QString::number(i))->isChecked();
        GameData game;
        game.gameName = gameName;
        game.gameTime = gameTime;
        game.score = score;
        game.isWin = isWin;
        game.isSup = isSup;
        playerNameList.append(player);
        gameDataList.append(game);
    }
    playerManager.addNewGameData(playerNameList,gameDataList);
}

void AddGamePage::initPlayerList()
{
    qDebug()<<"AddGamePage::initPlayerList";
    if(playerList.isEmpty()) return;
    for(int i=1;i<=10;i++){
        this->findChild<QComboBox *>("player_"+QString::number(i))->clear();
        for(int j=0;j<playerList.size();j++){
            this->findChild<QComboBox *>("player_"+QString::number(i))->addItem(playerList[j].getPlayerName());
        }
    }
}
