#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "bit_rep.h"
class Helper;
class QPaintEvent;
	
class Widget : public QWidget {
Q_OBJECT
public:
    Widget(Helper *helper, QWidget *parent, BitRep &br);
public slots:
    void animate();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Helper *helper;
    bool elapsed;
    int x, y;
    BitRep&my_bitrep;
    int highlight;
};
#endif