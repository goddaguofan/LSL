#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("LSL_v1.0");
    gotoRankPage();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rankBtn_clicked()
{
    gotoRankPage();
}

void MainWindow::on_addGameBtn_clicked()
{
    gotoAddGamePage();
}

void MainWindow::on_playerBtn_clicked()
{
    gotoPlayerPage();
}

void MainWindow::hideAllPage()
{
    if(rankPage != nullptr){
        rankPage->hide();
        delete rankPage;
        rankPage =nullptr;
    }
    if(addGamePage != nullptr){
        addGamePage->hide();
        delete addGamePage;
        addGamePage =nullptr;
    }
    if(playerPage != nullptr){
        playerPage->hide();
        delete playerPage;
        playerPage =nullptr;
    }
}

void MainWindow::gotoRankPage()
{
    hideAllPage();
    if(rankPage == nullptr) rankPage = new RankPage();
    rankPage->setParent(ui->groupBox_2);
    rankPage->show();
}

void MainWindow::gotoAddGamePage()
{
    hideAllPage();
    if(addGamePage == nullptr) addGamePage = new AddGamePage();
    addGamePage->setParent(ui->groupBox_2);
    addGamePage->show();
}

void MainWindow::gotoPlayerPage()
{
    hideAllPage();
    if(playerPage == nullptr) playerPage = new PlayerPage();
    playerPage->setParent(ui->groupBox_2);
    playerPage->show();
}
