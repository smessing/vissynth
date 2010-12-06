
#ifndef HELPER_H
#define HELPER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include "bit_rep.h"
class QPainter;
class QPaintEvent;

class Helper {
public:
    Helper();
    void paint(QPainter *painter, QPaintEvent *event,int highlight,BitRep &br);
private:
    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
};
#endif