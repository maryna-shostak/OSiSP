#include "Health.h"
#include "Game.h"
#include <QFont>

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    if (health>0){
        health--;
    }
    setPlainText(QString("Health: ") + QString::number(health));
    if (health==0) {
        game->GameOver(false);
    }
}

int Health::getHealth(){
    return health;
}

