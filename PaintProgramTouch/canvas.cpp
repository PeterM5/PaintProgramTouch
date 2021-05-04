#include "canvas.h"
#include <QPainter>

Canvas::Canvas() :
    QTabWidget()
{

}

void Canvas::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
    Pixel p(40,40,20,20,20);
    p.copyToBuffer(painter);
}
