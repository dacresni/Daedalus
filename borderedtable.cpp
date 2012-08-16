#include "borderedtable.h"
#include <QStyleOption>

BorderedTable::BorderedTable( QWidget *parent) :
    QFocusFrame(parent)
{
    QFocusFrame::initStyleOption(new QStyleOptionFocusRect);
    QFocusFrame::setFrameShape(QFrame::Box);
    QFocusFrame::setLineWidth(5);
    //setLineWidth( 5);
    //setMidLineWidth();
}

void BorderedTable::setWidget(QWidget * widget) {
    QFocusFrame::setWidget(widget);
    QRect oldrect = widget->rect();
    QPoint newPt = QPoint(oldrect.topLeft());
    QRect newrect =  QRect(newPt.x(), newPt.y(), oldrect.height() + 2 , oldrect.height() + 2);
    this->setGeometry(newrect);
}
