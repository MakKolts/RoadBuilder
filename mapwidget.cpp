#include "mapwidget.h"

#include <QKeyEvent>
#include <QPointF>

MapWidget::MapWidget(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::BspTreeIndex);
    scene->setSceneRect(0, 0, 640, 480);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(640, 480);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setWindowTitle(tr("Elastic Nodes"));

    lines.append(new RoadLine(QPointF(50, 100), QPointF(250, 100)));
    lines.append(new RoadLine(QPointF(150, 100), QPointF(150, 300)));
    lines.append(new RoadLine(QPointF(50, 300), QPointF(250, 300)));

    for (auto line: lines)
    {
        scene->addItem(line);
    }
}

void MapWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

#if QT_CONFIG(wheelevent)
void MapWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}
#endif

void MapWidget::zoomIn()
{
    scaleView(qreal(1.2));
}

void MapWidget::zoomOut()
{
    scaleView(1 / qreal(1.2));
}

void MapWidget::setTime(int time)
{
    for (auto line: lines)
    {
        line->setTime(time);
    }
}
