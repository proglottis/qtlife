#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "standardboard.h"
#include "standardrule.h"
#include "standardlife.h"
#include "boarditem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), lifeTimer(0)
{
    Board *board1 = new StandardBoard(100, 100, true);
    Board *board2 = new StandardBoard(100, 100, true);
    Rule *rule = new StandardRule();
    life = new StandardLife(board1, board2, rule);
    life->setParent(this);
    board1->setParent(life);
    board1->setParent(life);
    rule->setParent(life);

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    BoardItem *boarditem = new BoardItem(life->getBoard());
    QObject::connect(life, SIGNAL(stepped(Board *)), boarditem, SLOT(step(Board *)));
    scene->addItem(boarditem);

    ui->gameView->setScene(scene);
    ui->gameView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPlay_Pause_toggled(bool )
{
    if(lifeTimer == 0) {
        lifeTimer = life->startTimer(100);
        ui->actionPlay_Pause->setChecked(true);
    }
    else {
        life->killTimer(lifeTimer);
        ui->actionPlay_Pause->setChecked(false);
        lifeTimer = 0;
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionClear_triggered()
{
    life->getBoard()->clear();
    life->step();
}
