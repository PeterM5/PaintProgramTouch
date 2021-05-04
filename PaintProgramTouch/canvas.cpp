#include "canvas.h"
#include <QPainter>

Canvas::Canvas(uint width, uint height) :
    QTabWidget()
{

    for (uint x = 0; x < width; x++)
    {
        m_pixels.push_back(std::vector<Pixel>());
        for(uint y = 0; y < height; y++)
        {
            m_pixels[x].push_back(Pixel{0,0,0});
        }
    }

    for (uint x = 0; x < width; x++)
    {
        for (uint y = 0; y < height/2; y++)
        {
            m_pixels[x][y].red = 255;
        }
    }
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

            QRect rect = QRect(x*1, y*1, 1, 1);
            painter.fillRect(rect, QColor(m_pixels[x][y].red,m_pixels[x][y].green,m_pixels[x][y].blue));
        }
    }
}
