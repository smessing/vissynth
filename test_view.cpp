#include <QApplication>
#include "view.h"
#include "bit_rep.h"

int testView(int argc, char *argv[]) {	
    // Yui's tester for the window. you can mimic the way to call thing from here
    bool r = false;
    QApplication app(argc, argv);
    View window(1000);
    BitRep bitr(15,15);
	//window.refresh();
    for(int x = 0; x < 15; x++) {
        for(int y = 0; y<15; y++) {
            bitr.setBit(x,y,r);
            r = !r;
        }
    }
    window.load(bitr);
    window.show();
    return app.exec();
}