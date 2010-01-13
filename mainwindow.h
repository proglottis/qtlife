#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QGraphicsScene>

#include "life.h"

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindowClass *ui;
    Board *blankboard;
    Life *life;
    int lifeTimer;
    QGraphicsScene *scene;

private slots:
    void on_actionClear_triggered();
    void on_actionExit_triggered();
    void on_actionPlay_Pause_toggled(bool );
};

#endif // MAINWINDOW_H
