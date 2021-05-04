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

    QRect rect = QRect(290, 20, 70, 40);
    painter.drawRect(rect);
}
