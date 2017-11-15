#ifndef MAPWIDGET_H
#define MAPWIDGET_H

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

protected:
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void scaleView(qreal scaleFactor);

private:
    int m_originX;
    int m_originY;
    bool leftMousePressed = false;
};

#endif // MAPWIDGET_H
