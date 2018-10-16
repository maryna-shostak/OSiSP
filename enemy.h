#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int health;
public:
    Enemy(QGraphicsItem * parent=0);
    void SetLevel();
    void HealthDecrease();
    int getHealth();
public slots:
    void move();
};

#endif // ENEMY_H
