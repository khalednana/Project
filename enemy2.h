#ifndef ENEMY2_H
#define ENEMY2_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <QRandomGenerator>
class enemy2 : public QObject, public QGraphicsPixmapItem
{
public:
    enemy2(int boardData[11][11]);
public slots:
    void movement();
private:
    int row, column;
    int data[11][11];
    int health;
   QTimer *timer;
   QRandomGenerator generator;
private slots:



};


#endif // ENEMY2_H
