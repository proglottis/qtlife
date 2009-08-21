#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "standardboard.h"
#include "boarditem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), boardTimer(0)
{
    board = new StandardBoard(15, 15, true);
    board->setParent(this);

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    BoardItem *boarditem = new BoardItem(board);
    QObject::connect(board, SIGNAL(stepped()), boarditem, SLOT(step()));
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
    if(boardTimer == 0) {
        boardTimer = board->startTimer(100);
        ui->actionPlay_Pause->setChecked(true);
    }
    else {
        board->killTimer(boardTimer);
        ui->actionPlay_Pause->setChecked(false);
        boardTimer = 0;
    }
}
