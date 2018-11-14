#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "Player.h"
#include "Score.h"
#include "Health.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

    void start();
    void GameOver(bool);
signals:
    void WinSignal();
    void LoseSignal();
};

#endif // GAME_H
