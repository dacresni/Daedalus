    #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QAction;
class MainDocument;
class QUndoStack;

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

private:
    Ui::MainWindow *ui;
    MainDocument *Document;
    QUndoStack *undoStack;


};

#endif // MAINWINDOW_H
