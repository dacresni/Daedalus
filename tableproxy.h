#ifndef TABLEPROXY_H
#define TABLEPROXY_H

#include <QGraphicsProxyWidget>
class TableProxy : public QGraphicsProxyWidget
{
public:
    TableProxy();
    //void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * event ) {
        QGraphicsItem::mouseMoveEvent(event);
    }

};

#endif // TABLEPROXY_H
