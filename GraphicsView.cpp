#include "GraphicsView.h"
#include "QDebug"
#include <qmath.h>

GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{

}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
    static int zoom=0;

    int zoomTmp = qMax(qMin(10, zoom+event->angleDelta().y()/120), -10);
    if(10 > zoomTmp && zoomTmp > -10)
    {
        qreal scl = qPow(2, 0.5*(zoom-zoomTmp));
        scale(scl,scl);
        zoom = zoomTmp;
    }

    event->accept();
}
