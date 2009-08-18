#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "standardboard.h"
#include "boarditem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), boardTimer(0)
{
    board = new StandardBoard(100, 100, true);
    scene = new QGraphicsScene();
    ui->setupUi(this);
    BoardItem *boarditem = new BoardItem(board);
    QObject::connect(board, SIGNAL(stepped()), boarditem, SLOT(step()));
    scene->addItem(boarditem);
    ui->gameView->setScene(scene);
    ui->gameView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete board;
}

void MainWindow::on_actionPlay_Pause_toggled(bool )
{
    if(boardTimer == 0) {
        boardTimer = board->startTimer(100);
    }
    else {
        board->killTimer(boardTimer);
        boardTimer = 0;
    }
}
