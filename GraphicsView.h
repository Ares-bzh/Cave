#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0);

protected:
    void wheelEvent(QWheelEvent *event);

signals:

public slots:
};

#endif // GRAPHICSVIEW_H
