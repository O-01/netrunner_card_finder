#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlistwidget.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cardList_itemClicked(QListWidgetItem *item);

    void on_dropFormat_currentIndexChanged(int index);

    void on_searchField_textChanged();

    void on_cardList_itemSelectionChanged();

    void on_cardList_currentRowChanged(int currentRow);

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
