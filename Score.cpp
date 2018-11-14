#include "Score.h"
#include "Game.h"
#include <QFont>

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    if (score==50) {        
        game->GameOver(true);
        return;
    } else setPlainText(QString("Score: ") + QString::number(score)); // Health: 2
}

int Score::getScore(){
    return score;
}
