#ifndef CANVAS_H
#define CANVAS_H

#include "pixel.h"
#include <QTabWidget>

class Canvas: public QTabWidget
{
    Q_OBJECT
public:
    Canvas();

private:
    void paintEvent(QPaintEvent* paintEvent) override;
};

#endif // CANVAS_H
