#include <QtGui>
#include "widget.h"
#include "helper.h"

Widget::Widget(Helper *helper, QWidget *parent,BitRep&b) : QWidget(parent), helper(helper),my_bitrep(b) {
    highlight=0;
    setFixedSize(500, 500);
}

void Widget::animate() {
    /*elapsed = !elapsed;
    x++;
    y++;*/
    //highlight++;
    my_bitrep.incrementCol();
    highlight = my_bitrep.getCurrentCol();
    repaint();
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    helper->paint(&painter, event,highlight,my_bitrep);
    painter.end();
}

