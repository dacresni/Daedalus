#ifndef BORDEREDTABLE_H
#define BORDEREDTABLE_H

#include <QWidget>
#include <QFocusFrame>
class BorderedTable : public QFocusFrame
{
    Q_OBJECT
public:
    explicit BorderedTable(QWidget *parent = 0);
    void setWidget(QWidget * widget);
signals:
    
public slots:
    
};

#endif // BORDEREDTABLE_H
