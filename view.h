#ifndef WINDOW_H
#define WINDOW_H

#include <QString>
#include <QWidget>
#include "helper.h"
#include "bit_rep.h"

class QLabel;
class QWidget;

class View : public QWidget {
    Q_OBJECT
public:
    View(int time);
    //void refresh();
    //call the widget underneath which will inturn call the helper
    void load(BitRep &br);
private:
    int my_time;
    Helper helper;
    //I have to comment out because it will not run on here
    QWidget *my_widget;	
};
#endif
