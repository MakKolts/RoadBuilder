#include "window.h"
#include "mapwidget.h"
#include <QtWidgets>

Window::Window()
{
    MapWidget *map = new MapWidget;
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(map);

    QSlider *slider = new QSlider(Qt::Horizontal);
    mainLayout->addWidget(slider);
    setWindowTitle(tr("Crossroads"));
    setLayout(mainLayout);

    connect(slider, SIGNAL(valueChanged(int)), map, SLOT(setTime(int)));
}
