/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed 13. Jan 16:30:23 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionPlay_Pause;
    QAction *actionExit;
    QAction *actionClear;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *gameView;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuLife;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(459, 422);
        actionPlay_Pause = new QAction(MainWindowClass);
        actionPlay_Pause->setObjectName(QString::fromUtf8("actionPlay_Pause"));
        actionPlay_Pause->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/actions/play-pause"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay_Pause->setIcon(icon);
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionClear = new QAction(MainWindowClass);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/actions/clear"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon1);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gameView = new QGraphicsView(centralWidget);
        gameView->setObjectName(QString::fromUtf8("gameView"));

        horizontalLayout->addWidget(gameView);

        MainWindowClass->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindowClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 459, 25));
        menuLife = new QMenu(menuBar);
        menuLife->setObjectName(QString::fromUtf8("menuLife"));
        MainWindowClass->setMenuBar(menuBar);

        toolBar->addAction(actionPlay_Pause);
        toolBar->addAction(actionClear);
        menuBar->addAction(menuLife->menuAction());
        menuLife->addAction(actionPlay_Pause);
        menuLife->addAction(actionClear);
        menuLife->addAction(actionExit);
        menuLife->addSeparator();

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "QtLife", 0, QApplication::UnicodeUTF8));
        actionPlay_Pause->setText(QApplication::translate("MainWindowClass", "Play/Pause", 0, QApplication::UnicodeUTF8));
        actionPlay_Pause->setShortcut(QApplication::translate("MainWindowClass", "Space", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindowClass", "E&xit", 0, QApplication::UnicodeUTF8));
        actionClear->setText(QApplication::translate("MainWindowClass", "Clear", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindowClass", "Main Toolbar", 0, QApplication::UnicodeUTF8));
        menuLife->setTitle(QApplication::translate("MainWindowClass", "&Life", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
