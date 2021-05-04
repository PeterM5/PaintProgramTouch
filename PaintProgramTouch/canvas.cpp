#include "canvas.h"
#include <QPainter>

Canvas::Canvas(uint width, uint height) :
    QTabWidget()
{

    for (int x = 0; x < width; x++)
    {
        m_pixels.push_back(std::vector<Pixel>());
        for(int y = 0; y < height; y++)
        {
            m_pixels[x].push_back(Pixel());
        }
    }

    Pixel p;
    p.blue = 20;
    p.green = 20;
    p.red = 100;
    m_pixels[10][10] = p;
}

void Canvas::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);

    painter.scale(1, 1);//todo set as member variable and set through scrolling

    for (int x = 0; x < m_pixels.size(); x++)
    {
        for(int y = 0; y < m_pixels[x].size(); y++)
        {
            QPen pen = QPen();
            //todo

            QRect rect = QRect(x, y, 1, 1);
            painter.drawRect(rect);
        }
    }
}
