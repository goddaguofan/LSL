#include "playerpage.h"
#include "ui_playerpage.h"
#include <QMessageBox>

PlayerPage::PlayerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerPage)
{
    ui->setupUi(this);
}

PlayerPage::~PlayerPage()
{
    delete ui;
}

void PlayerPage::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    qDebug()<<"PlayerPage init";
    initPlayerPage();
}

void PlayerPage::on_addNewPlayerBtn_clicked()
{
    bool addOk = playerManager.addNewPlayer(ui->newPlayer->text());
    if(addOk){
        QMessageBox::information(nullptr, "Yes", "玩家已添加!");
    }else{
         QMessageBox::critical(nullptr, "Error", "玩家已存在!");
    }

}

void PlayerPage::on_newPlayer_returnPressed()
{
    bool addOk = playerManager.addNewPlayer(ui->newPlayer->text());
    if(addOk){
        QMessageBox::information(nullptr, "Yes", "玩家已添加!");
    }else{
         QMessageBox::critical(nullptr, "Error", "玩家已存在!");
    }
}

void PlayerPage::initPlayerPage()
{
    playerList = playerManager.getPlayerList();
}
