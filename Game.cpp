#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include "Enemy.h"

Game::Game(QWidget *parent) {

}

void Game::start()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,600);
    setBackgroundBrush(QBrush(QImage(":/pics/background.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600,600);
    player = new Player();
    player->setPos(270,550); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);
    show();
}


void Game::GameOver(bool bl){
    if (bl)
        emit WinSignal();
    else
        emit LoseSignal();
    this->close();
}
