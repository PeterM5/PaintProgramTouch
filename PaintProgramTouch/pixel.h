#ifndef PIXEL_H
#define PIXEL_H
#include <QPainter>
typedef unsigned char Color;
class Pixel
{
public:
    Pixel(uint x,uint y,Color red,Color green,Color blue);
    void copyToBuffer(QPainter &painter);
private:
    uint x,y;
    Color red;
    Color green;
    Color blue;
};

#endif // PIXEL_H
