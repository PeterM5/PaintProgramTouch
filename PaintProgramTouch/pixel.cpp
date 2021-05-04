#include "pixel.h"

Pixel::Pixel(uint x,uint y,Color red,Color green,Color blue):x(x),y(y), red(red), green(green), blue(blue)
{

}

void Pixel::copyToBuffer(QPainter &painter)
{
    QRect rect = QRect(x, y, 1, 1);
    painter.drawRect(rect);
}
