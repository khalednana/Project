#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include <QDebug>
#include "heart.h"
#include "enemy2.h"
#include <QMessageBox>
Player::Player(int boardData[11][11])
{
    // Set Image
    image.load("/Users/khalednana/Desktop/project/tweety.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
//    for (int i = 0; i < 3; i++) {
//        hearts[i].load("/Users/khalednana/Desktop/project/heart.png");
//        hearts[i] = hearts[i].scaledToWidth(20);
//        hearts[i] = hearts[i].scaledToHeight(20);
//        setPixmap(hearts[i]);

//    }

    // Set Position
    row = 5;
    column = 5;
    health=3;
    setPos(50 + 5 * 50, 50 + 5 * 50);

    // Set data Array
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            data[i][j] = boardData[i][j];
}
void Player::keyPressEvent(QKeyEvent* event)
{

    if (event->key() == Qt::Key_Up && data[row - 1][column] >= 0)
    {
        row--;

    }
    else if (event->key() == Qt::Key_Down && data[row + 1][column] >= 0)
    {
        row++;

    }
    else if (event->key() == Qt::Key_Right && data[row][column + 1] >= 0)
    {
        column++;

    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
    {
        column--;

    }
//    else if (event->key() == Qt::Key_Space)
//    {
//        bullet * Bullet = new bullet();
//        qDebug() << "bullet is created";
//        Bullet->setPos(50 + column * 50, 50 + row * 50);
//        scene()->addItem(Bullet);

//    }
    setPos(50 + column * 50, 50 + row * 50);

    QList<QGraphicsItem*> items = collidingItems();
    for (int i = 0; i < items.size(); i++)
    {
        if (typeid(*items[i]) == typeid(Food)){
            scene()->removeItem(items[i]);
            immune = true;
            image.load("/Users/khalednana/Desktop/project/gun.png");
            image = image.scaledToWidth(25);
            image = image.scaledToHeight(50);
            this->setPixmap(image);
            this->update();
           }
        if (typeid(*items[i]) == typeid(enemy)){

                    health--;


            }
        if (typeid(*items[i]) == typeid(enemy2)){

                    health--;


            }
        if (typeid(*items[i]) == typeid(bullet)){
            scene()->removeItem(items[i]);

           }
         if (health==0)
         {
        QMessageBox box;
        box.setText("Game Over");
        box.exec();

         }
}
}

