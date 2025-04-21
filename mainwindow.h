#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "functions.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbAddColumn_clicked();

    void on_pbAddRow_clicked();

    void on_pbRemoveColumn_clicked();

    void on_pbRemoveRow_clicked();

    void on_pbShow_clicked();

    void on_pbAddRow2_clicked();

    void on_pbRemoveRow2_clicked();

    void on_pbAddColumn2_clicked();

    void on_pbRemoveColumn2_clicked();

    void on_pbPlus_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
