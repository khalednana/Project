#include "enemy.h"
#include "player.h"
#include <QTimer>
#include <qglobal.h>
#include <QRandomGenerator>
#include "QtCore/qobjectdefs.h"
extern Player p;

enemy::enemy(int boardData[11][11])
{

    // Set Image
    QPixmap image("/Users/khalednana/Desktop/project/enemy2.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    row = 8;
    column = 8;
    setPos(50 + column * 50, 50 + row * 50);
    health=2;


    // Set data Array
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            data[i][j] = boardData[i][j];

    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&enemy::movement);
    timer->start(1000);

}
void enemy::movement()
{

    int x;
    x=generator.bounded(1, 5);
//    qDebug()<<x;
    if (x != 2 && x !=3 && x != 4 && data[row - 1][column] >= 0)
    {
    row--;
    setPos(50 + column * 50, 50 + row * 50);
    }
       if (x != 1 && x !=3 && x != 4 && data[row + 1][column] >= 0)
        {
           row ++;
           setPos(50 + column * 50, 50 + row * 50);
        }

           if (x != 1 && x !=2 && x != 4 && data[row][column + 1] >= 0)
           {
               column++;
               setPos(50 + column * 50, 50 + row * 50);

           }
           if (x != 1 && x != 2 && x != 3 && data[row][column - 1] >= 0)
           {
               column--;
               setPos(50 + column * 50, 50 + row * 50);
           }

//    if (data[row - 1][column] <= 0)
//    {
//        row++;
//        setPos(50 + column * 50, 50 + row * 50);
//    }

        //move enemy towards player
        //move enemy towards player


//        if (column > p.column)
//        {
//            if (data[row][column - 1] <= 0)
//            {
//                setPos(column-50,row); // left
//            }
//        }else {
//            if (data[row][column + 1] <= 0)
//            {
//                setPos(column+50,row); // right
//            }
//        }
//        if (y() > p.y())
//        {
//            if (data[row - 1][column] <= 0)
//            {
//                setPos(x(),y()-50); // up
//            }
//        }else {
//            if (data[row + 1][column] <= 0)
//            {
//                setPos(x(),y()+50); // down
//            }
//        }
//        return;
//        }

//        //check for collision, if true destroy both
//        QList<QGraphicsItem*> colliding_items = collidingItems();

//        for (int i = 0, n = colliding_items.size(); i < n; ++i)
//        {
//            if(typeid (*(colliding_items[i])) == typeid (Player))
//            {
//                //decrease health
//                game->health->decrease();

//                if (game->health->getHealth() == 0)
//                {
//                    game->end();
//                }

//                //remove the enemy from the scene
//                scene()->removeItem(this);

//                //delete items to save storage
//                delete this;

//                return;
//            }



//    while(data[row - 1][column] >= 0)
//    {
//        row --;
//        setPos(50 + column * 50, 50 + row * 50);
     //}
//   while(data[row + 1][column] >= 0)
//    {
//       row ++;
//       setPos(50 + column * 50, 50 + row * 50);
//    }
//    while(data[row][column + 1] >= 0)
//    {
//        column++;
//        setPos(50 + column * 50, 50 + row * 50);

//    }
//    while(data[row][column - 1] >= 0)
//    {
//        column--;
//        setPos(50 + column * 50, 50 + row * 50);
//    }



//    if (event->key() == Qt::Key_Up && data[row - 1][column] >= 0)
//    {
//        row--;
//    }
//    else if (event->key() == Qt::Key_Down && data[row + 1][column] >= 0)
//    {
//        row++;
//    }
//    else if (event->key() == Qt::Key_Right && data[row][column + 1] >= 0)
//    {
//        column++;
//    }
//    else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
//    {
//        column--;
//    }


}

