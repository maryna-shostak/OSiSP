#include "startmenu.h"
#include <QPushButton>
#include <QGridLayout>
#include "Game.h"
#include <QDebug>
#include <QApplication>
#include <QLabel>
#include <QFont>
Game * game;

StartMenu::StartMenu()
{
    game = new Game();
    grid = new QGridLayout;
    QPushButton *start_but = new QPushButton("Start");
    QPushButton *exit_but = new QPushButton("Exit");

    win_text = new QLabel("You win");
    lose_text = new QLabel("You lose");
    QFont font( "Arial", 32, QFont::Bold);
    win_text->setFont(font);
    lose_text->setFont(font);
    win_text->setStyleSheet("QLabel { color: blue; }");
    lose_text->setStyleSheet("QLabel { color: red; }");

    grid->addWidget(start_but, 1, 0);
    grid->addWidget(exit_but, 1, 1);
    setLayout(grid);

    QObject::connect(start_but, SIGNAL(clicked(bool)), this, SLOT(StartEvent()));
    QObject::connect(exit_but, SIGNAL(clicked(bool)), this, SLOT(ExitEvent()));

    QObject::connect(game, SIGNAL(WinSignal()), this, SLOT(WinEvent()));
    QObject::connect(game, SIGNAL(LoseSignal()), this, SLOT(LoseEvent()));
}

void StartMenu::StartEvent()
{
    game->start();
}

void StartMenu::ExitEvent()
{
    QApplication::quit();
}

void StartMenu::WinEvent()
{
    this->grid->addWidget(win_text, 0, 0);
}

void StartMenu::LoseEvent()
{
    this->grid->addWidget(lose_text, 0, 0);
}


