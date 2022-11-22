#include "food.h"

Food::Food()
{
    // Set Image
    QPixmap image("/Users/khalednana/Desktop/project/Ice Cream.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    //setPos(50 + 5 * 50, 50 + 5 * 50);
}
