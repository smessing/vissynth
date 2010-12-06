#include <QtGui>
#include "helper.h"
	
Helper::Helper() {
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));
    background = QBrush(QColor(205, 200, 177));
    //background = QBrush(QColor(64, 32, 64));
    circleBrush = QBrush(gradient);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(50);
}
	
// change elapsed to be bool
void Helper::paint(QPainter *painter, QPaintEvent *event,int highlight, BitRep &br) {
		/*original code
        painter->fillRect(event->rect(), background);
		painter->translate(100, 100);

        painter->save();
        painter->setBrush(circleBrush);
        painter->setPen(circlePen);
		if(black == true){
        int n = 30;
        for (int i = 0; i < n; ++i) {
            painter->rotate(30);
            qreal radius = 0 + 120.0*((i+i)/n);
            qreal circleRadius = 1 + ((i+i)/n)*20;
			painter->drawRect(i+1,i+2,radius,circleRadius);
        }
		}
        painter->restore();

        painter->setPen(textPen);
        painter->setFont(textFont);
        painter->drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, "Qt");
		*/
		
    // modified
	int width = 15;
	int height = 15;
	int posx,posy;
	//draw the bg
	painter ->fillRect(event->rect(),background);
	//draw the rectangle
	for(int row = 0;row< br.getRows();row++) {
		posx = row*width;
		for(int col= 0;col <br.getCols();col++) {
			bool current_pos = br.getBit(row,col);
			posy = col*height;
			if(col == highlight && current_pos)
				painter->setBrush(Qt::yellow);
			//if there is an image then draw black square
			else if(current_pos)
				painter->setBrush(Qt::black);
			//otherwise set it to be white
			else 
				painter->setBrush(Qt::white);
		painter->drawRect(QRect(posx,posy,width,height));
		}
	}
}

