#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

void showMessage(const QString& msg){
    QMessageBox mb;
    mb.setText(msg);
    mb.exec(); // показывает окно

}

QTableWidgetItem* getItem(QTableWidget* tw, int i, int j){
    QTableWidgetItem* item = tw->item(i,j);
    if(!item){
        item = new QTableWidgetItem;
        item->setText(QString::number(0));
        tw->setItem(i, j, item);
    }
    return item;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbAddColumn_clicked()
{
    int cols = ui->twData->columnCount(); // считает количество колонок
    ui->twData->setColumnCount(cols + 1); // добавляет один столбец
}


void MainWindow::on_pbAddRow_clicked()
{
    int rows = ui->twData->rowCount(); // считает количество строк
    ui->twData->setRowCount(rows + 1); // добавляет одну строку
}


void MainWindow::on_pbRemoveColumn_clicked()
{
    int cols = ui->twData->columnCount(); // считает количество колонок
    if (cols > 0)
        ui->twData->setColumnCount(cols - 1); // убирает один столбец
}

void MainWindow::on_pbRemoveRow_clicked()
{
    int rows = ui->twData->rowCount(); // считает количество строк
    if (rows > 0)
        ui->twData->setRowCount(rows - 1); // убирает одну строку
}


// void MainWindow::on_pbShow_clicked()
// {
//     int rows = ui->twData->rowCount(); // считает количество строк
//     int cols = ui->twData->columnCount(); // считает количество колонок

//     QString s = "";
//     for (int i = 0; i < rows; ++i){
//         for (int j = 0; j < cols; ++j){
//             QTableWidgetItem* getItem(ui->twData->item(i,j));
//             // if (!item){
//             //     item = new QTableWidgetItem;
//             //     ui->twData->setItem(i, j, item);
//             // }
//             // s += item->text() + "\t";
//         }
//         s += "\n";
//     }
//     showMessage(s);
// }


void MainWindow::on_pbAddRow2_clicked()
{
    int rows = ui->twData2->rowCount();
    ui->twData2->setRowCount(rows + 1);
}


void MainWindow::on_pbRemoveRow2_clicked()
{
    int rows = ui->twData2->rowCount();
    if (rows > 0)
        ui->twData2->setRowCount(rows - 1);
}


void MainWindow::on_pbAddColumn2_clicked()
{
    int cols = ui->twData2->columnCount();
    ui->twData2->setColumnCount(cols + 1);
}


void MainWindow::on_pbRemoveColumn2_clicked()
{
    int cols = ui->twData2->columnCount();
    if (cols > 0)
        ui->twData2->setColumnCount(cols - 1);
}




void MainWindow::on_pbPlus_clicked()
{
    int rows1 = ui->twData->rowCount();
    int cols1 = ui->twData->columnCount();
    int rows2 = ui->twData2->rowCount();
    int cols2 = ui->twData2->columnCount();

    // pointer = 0;


    if (rows1 == rows2 && cols1 == cols2) {
        double** A = creation(rows1, cols1);
        double** B = creation(rows2, cols2);

        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols1; ++j) {
                QTableWidgetItem* item = getItem(ui->twData, i, j);

                if (!item){
                    QString s = "ERROR";
                    showMessage(s);
                }

                else{
                    A[i][j] = item->text().toDouble();
                }

            }

        }

        for (int i = 0; i < rows2; ++i) {
            for (int j = 0; j < cols2; ++j) {
                QTableWidgetItem* item = getItem(ui->twData, i, j);

                if (!item){
                    QString s = "ERROR";
                    showMessage(s);
                }

                else{
                    B[i][j] = item->text().toDouble();
                }

            }

        }
        double** S = creation(rows1, cols1);
        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols1; ++j) {
                S[i][j] = A[i][j] + B[i][j];
            }
        }
        ui->twResult->setColumnCount(cols1);
        ui->twResult->setRowCount(rows1);
        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols1; ++j) {
                QTableWidgetItem* item;
                item->setText(QString::number(S[i][j]));
                ui->twResult->setItem(i, j, item);
            }
        }


    }


    else {
        QString s = "ERROR: sizes mismatch";
        showMessage(s);
    }

}

