#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //read recent files to populate recent files menu
    pageStack= new QStackedLayout(ui->stackHolder);
    newSceneViewItem("New Page");
    //read preferences
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
bool MainWindow::maybeSave()
 {
     if (textEdit->document()->isModified()) {
         QMessageBox::StandardButton ret;
         ret = QMessageBox::warning(this, tr("Application"),
                      tr("The document has been modified.\n"
                         "Do you want to save your changes?"),
                      QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
         if (ret == QMessageBox::Save)
             return save();
         else if (ret == QMessageBox::Cancel)
             return false;
     }
     return true;
 }
*/
void MainWindow::newSceneViewItem(QString name)
{
//add a new spreadsheet to the documentTree
 QTreeWidgetItem* page= new QTreeWidgetItem();
 page->setText(0,name);
 //page->setIcon(1, QIcon(":graphics/pageIcon.svg"));
 ui->documentTree->addTopLevelItem(page);
 qDebug() <<"add new doc to tree";
 QGraphicsScene * scene= new QGraphicsScene;
 QGraphicsView * pageView = new QGraphicsView(scene);
 int index = pageStack->addWidget(pageView);
 pageStack->setCurrentWidget(pageView);
 scene->setBackgroundBrush(Qt::white);
 QString text= QString("page %1").arg(index);
 scene->addText(text);
 qDebug() <<"add new page view ";
//we can define a new widget to display the item using
 // page->setWidget()
}


void MainWindow::on_actionOpen_triggered()
{
    /*if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }*/

}

void MainWindow::on_actionNew_Sheet_triggered()
{
  newSceneViewItem("Blank Page");
}

void MainWindow::on_actionNew_triggered()
{
    //new document
}


void MainWindow::on_documentTree_itemChanged(QTreeWidgetItem *item, int column)
{
    qDebug() <<"docTree item changed";
}

void MainWindow::debugChanged(int index){
    qDebug()<<"widget changed";
    qDebug()<<index;
}

void MainWindow::on_documentTree_itemActivated(QTreeWidgetItem *item, int column)
{
    int index= ui->documentTree->indexOfTopLevelItem(item);
    pageStack->setCurrentIndex(index);
    qDebug() <<"item activated";
    qDebug()<<index;
}

void MainWindow::on_actionAddTable_triggered()
{
    //add table
    QTableWidget* newTable = new QTableWidget( 3, 3);
    newTable->setHorizontalHeaderLabels(QStringList()<<"1"<<"2"<<"3");
    newTable->setVerticalHeaderLabels(QStringList()<<"A"<<"B"<<"C");
    // row mod(26) = letter
    QWidget * thisPage = pageStack->currentWidget();
    QGraphicsView * thePage = dynamic_cast<QGraphicsView*>(thisPage);
    QGraphicsScene* thisScene = thePage->scene();
    thisScene->addWidget(newTable);
}
