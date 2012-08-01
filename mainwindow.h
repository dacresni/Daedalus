#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QGraphicsView>
#include <QStackedLayout>
#include <QTableWidget>

class QAction;
class QUndoStack;
class QTreeWidget;
class QTreeWidgetItem;
class QString;
class QFileDialog;
class QGraphicsScene;
class QGraphicsView;
class QStackedLayout;
class QTableWidget;
class QGraphicsItem;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_actionOpen_triggered();

    void on_actionNew_Sheet_triggered();

    void on_actionNew_triggered();

    void on_documentTree_itemChanged(QTreeWidgetItem *item, int column);

    void on_documentTree_itemActivated(QTreeWidgetItem *item, int column);

    void debugChanged(int index);

    void on_actionAddTable_triggered();


private:
    Ui::MainWindow *ui;
    QUndoStack *undoStack;
    QTreeWidget *docTree;
    QString currentFile;
    QStackedLayout * pageStack;
    //QList<GraphicsScene> sceneList;
    void newSceneViewItem(QString);
    bool maybeSave();
    //static const int  leafType = QTreeWidgetItem::UserType+1;
    //static const int pageType = QTreeWidgetItem::UserType;

};

#endif // MAINWINDOW_H
