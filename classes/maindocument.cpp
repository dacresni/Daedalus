#include "maindocument.h"

MainDocument::MainDocument(QObject *parent) :
    QObject(parent)
{
     *pageList = new QTreeWidgit(this);
}
MainDocument::NewSheet(QTreeWidgitItem *parent ) :
