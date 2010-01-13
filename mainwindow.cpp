#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "simpleboardcache.h"
#include "standardboard.h"
#include "standardrule.h"
#include "standardlife.h"
#include "boarditem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindowClass),
      blankboard(new StandardBoard(100, 100, true)),
      lifeTimer(0)
{
    BoardCache *cache = new SimpleBoardCache(50, blankboard);
    Board *board = new StandardBoard(*blankboard);
    Rule *rule = new StandardRule();
    life = new StandardLife(board, rule, cache);
    life->setParent(this);
    board->setParent(life);
    rule->setParent(life);

    cache->setParent(this);

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    BoardItem *boarditem = new BoardItem(cache);
    QObject::connect(life, SIGNAL(stepped(BoardCache *)), boarditem, SLOT(step(BoardCache *)));
    scene->addItem(boarditem);

    ui->gameView->setScene(scene);
    ui->gameView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete blankboard;
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
    life->getCache()->clear(blankboard);
    life->step();
}
