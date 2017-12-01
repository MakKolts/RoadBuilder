#ifndef ROADLINE_H
#define ROADLINE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QPointF>

class RoadLine : public QGraphicsItem
{
public:
    RoadLine(QPointF p1,QPointF p2);
    void setDensity(qreal current, qreal max_val);
    void setTime(int time);

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
 //   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPen pen;
    QColor color;

    QPointF sourcePoint;
    QPointF destPoint;

    qreal curDensity = 30;
    qreal maxDensity = 255;
    int penWidth = 7;
};

#endif // ROADLINE_H
