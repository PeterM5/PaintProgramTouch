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
    void wheelEvent(QWheelEvent* event);

    std::vector<std::vector<Pixel>> m_pixels;

    float m_zoomFactor = 1;
    const float m_cZoomIncrement = 0.1;
};

#endif // CANVAS_H
