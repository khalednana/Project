#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include "food.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:

public:
    Player(int boardData[11][11]);
    QPixmap image;
    int row, column;
    int data[11][11];
    int health;
    QPixmap hearts[3];
    bool immune= false;
public slots:
    void keyPressEvent(QKeyEvent* event);

};
#endif // PLAYER_H
