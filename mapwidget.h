#ifndef MAPWIDGET_H
#define MAPWIDGET_H
#include "roadline.h"

#include <QGraphicsView>

class MapWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapWidget(QWidget *parent = nullptr);

signals:

public slots:
    void zoomIn();
    void zoomOut();
    void setTime(int time);


protected:
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void scaleView(qreal scaleFactor);

private:
    int m_originX;
    int m_originY;
    bool leftMousePressed = false;

    QGraphicsScene *scene;
    QList<RoadLine*> lines;
};

#endif // MAPWIDGET_H
