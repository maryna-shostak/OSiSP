#include "mainwindow.h"
#include "startmenu.h"
#include "ui_mainwindow.h"

#include <QAction>
#include <QMenuBar>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *game_menu = menuBar()->addMenu("Game"); //Создаем меню бар и помещаяем в него первый пункт меню file
    QAction *about_menu = menuBar()->addAction("About"); // Добавляем в наш меню бар дополнительный пункт edit
    QAction *start_act = game_menu->addAction(tr("Start"));
    QAction *close_act = game_menu->addAction(tr("Close"));
    setFixedSize(500,500);
    StartMenu *start_wid = new StartMenu;
    setCentralWidget(start_wid);
}

MainWindow::~MainWindow()
{
    delete ui;
}
