#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include "Bullet.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 500;
    setPos(random_number,0);
    SetLevel();
    // drew the rect


    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::SetLevel()
{
    if (game->score->getScore()>30) {
        health = 3;
        setPixmap(QPixmap(":/pics/third_level.png"));
    } else if (game->score->getScore()>10) {
        health = 2;
        setPixmap(QPixmap(":/pics/second_level.png"));
    } else {
        health = 1;
        setPixmap(QPixmap(":/pics/first_level.png"));
    }

}

void Enemy::HealthDecrease()
{
    health--;
}

int Enemy::getHealth()
{
    return health;
}

void Enemy::move(){
    // move enemy down
    if(health==3) {
        setPos(x(),y()+10);
    } else if (health==2) {
        setPos(x(),y()+7);
    } else if (health==1){
        setPos(x(),y()+5);
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Bullet)){
            // increase the score

            game->score->increase();
            HealthDecrease();

            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];

            if (health == 0) {
                scene()->removeItem(this);
                delete this;
            }
            return;
        }
    }
    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}

