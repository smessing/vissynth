#include <QtGui>
#include "widget.h"
#include "view.h"

//I think int time have to corresponding to the delay between camera???? 
// the timer will determine when to update
View::View(int time) : QWidget() {
    //this is to send the time interval of each updating
    my_time = time;
    /* Widget *wid = new Widget(&helper, this);
    my_widget = wid;
    my_time = time;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(wid, 0, 0);
    setLayout(layout);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), native, SLOT(animate()));
    timer->start(time);
    setWindowTitle(tr("Bitrep in action"));*/
}
	
void View::load(BitRep &br) {
    Widget *wid = new Widget(&helper, this,br);
    my_widget = wid;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(wid, 0, 0);
    setLayout(layout);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), wid, SLOT(animate()));
    timer->start(my_time);
    setWindowTitle(tr("Bitrep in action"));
}
	/*void View::refresh()
	{
		//we should change it accordingly;;affect the update interval

		QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), my_widget, SLOT(animate()));
        timer->start(my_time);
	
		//my_widget -> animate();
	}*/