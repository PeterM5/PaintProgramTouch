#ifndef CANVAS_H
#define CANVAS_H

#include "pixel.h"
#include <QTabWidget>
#include <vector>

class Canvas: public QTabWidget
{
    Q_OBJECT
public:
    Canvas(uint width, uint height);

private:
    void paintEvent(QPaintEvent* paintEvent) override;

    std::vector<std::vector<Pixel>> m_pixels;
};

#endif // CANVAS_H
