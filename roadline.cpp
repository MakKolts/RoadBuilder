#include "roadline.h"
#include <QPainter>
#include <QMessageBox>

RoadLine::RoadLine(QPointF p1, QPointF p2) : sourcePoint(p1), destPoint(p2)
{

}

void RoadLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    qreal colorProportion = curDensity/maxDensity;
    QColor color(250*colorProportion, 250*(1-colorProportion), 0);
    QPen pen(color);
    pen.setWidth(penWidth);
    painter->setPen(pen);

    QLineF line(sourcePoint, destPoint);
    painter->drawLine(line);
    painter->drawRect(sourcePoint.x(), sourcePoint.y(),
                      destPoint.x() - sourcePoint.x(), destPoint.y() - sourcePoint.y());
}

QRectF RoadLine::boundingRect() const
{
    qreal left = sourcePoint.x() - penWidth/2;
    qreal top = sourcePoint.y() - penWidth/2;
    qreal width = destPoint.x() - sourcePoint.x() + penWidth;
    qreal height = destPoint.y() - sourcePoint.y() + penWidth;

    return QRectF(left, top, width, height);
}

void RoadLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("title");
    msgBox.setText("Question");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
      int kek = 1;
    }
    QGraphicsItem::mousePressEvent(event);
}

void RoadLine::setDensity(qreal current, qreal max_val)
{
    this->curDensity = current;
    this->maxDensity = max_val;
}
