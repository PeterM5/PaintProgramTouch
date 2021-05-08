#include "canvas.h"
#include <QPainter>
#include <QWheelEvent>

Canvas::Canvas(uint width, uint height) :
    QTabWidget()
{
    // Initalize memory for pixel data
    for (uint x = 0; x < width; x++)
    {
        m_pixels.push_back(std::vector<Pixel>());
        for(uint y = 0; y < height; y++)
        {
            m_pixels[x].push_back(Pixel{0,0,0}); // 0,0,0 is black,  255,255,255 is white
        }
    }

    // Set half the canvas to the color red
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

    painter.scale(m_zoomFactor, m_zoomFactor);

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

void Canvas::wheelEvent(QWheelEvent* event)
{
    if(event->angleDelta().y() > 0)
    {
        m_zoomFactor += m_cZoomIncrement;
    }
    else if(event->angleDelta().y() < 0)
    {
         m_zoomFactor -= m_cZoomIncrement;
    }

    //Call to redraw
    update();
}
