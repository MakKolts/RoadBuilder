#include "window.h"
#include "mapwidget.h"
#include <QtWidgets>

Window::Window()
{
    MapWidget *map = new MapWidget;
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(map);

    mainLayout->addWidget(new QSlider(Qt::Horizontal));
    setWindowTitle(tr("Crossroads"));
    setLayout(mainLayout);
}
