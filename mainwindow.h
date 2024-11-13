#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "patient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    Patient tmppatient;
};

#endif // MAINWINDOW_H
