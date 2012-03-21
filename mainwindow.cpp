#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "documenttreeitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    documentTree = ui->documentTree;
    //read recent files to populate recent files menu
    //read preferences



}

MainWindow::~MainWindow()
{
    delete ui;
}

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


void MainWindow::on_actionOpen_triggered()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }

}


void MainWindow::on_actionNew_Sheet_triggered()
{
   //add a new spreadsheet to the pageList documentTree
  //  ui->documentTree->addTopLevelItem( new DocumentTreeItem(type = DocumentTreeItem::pageType));
    ui->documentTree->addTopLevelItem( new DocumentTreeItem(type = QTreeWidget::pageType));
}

void MainWindow::on_actionNew_triggered()
{
    //new document
}

