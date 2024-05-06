#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "RankPage/rankpage.h"
#include "AddGamePage/addgamepage.h"
#include "PlayerPage/playerpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rankBtn_clicked();

    void on_addGameBtn_clicked();

    void on_playerBtn_clicked();

private:
    void hideAllPage();
    void gotoRankPage();
    void gotoAddGamePage();
    void gotoPlayerPage();

private:
    Ui::MainWindow *ui;
    RankPage *rankPage = nullptr;
    AddGamePage *addGamePage = nullptr;
    PlayerPage *playerPage = nullptr;

};
#endif // MAINWINDOW_H
