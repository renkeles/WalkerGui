#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "walker.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    labels[0][0] = ui->label_1;
    labels[0][1] = ui->label_2;
    labels[0][2] = ui->label_3;
    labels[0][3] = ui->label_4;
    labels[1][0] = ui->label_5;
    labels[1][1] = ui->label_6;
    labels[1][2] = ui->label_7;
    labels[1][3] = ui->label_8;
    labels[2][0] = ui->label_9;
    labels[2][1] = ui->label_10;
    labels[2][2] = ui->label_11;
    labels[2][3] = ui->label_12;
    labels[3][0] = ui->label_13;
    labels[3][1] = ui->label_14;
    labels[3][2] = ui->label_15;
    labels[3][3] = ui->label_16;

    count = 0;

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            labels[i][j]->setText(QString::number(count));
            labels[i][j]->setStyleSheet("QLabel {background-color: yellow;}");
        }

    }

    labels[0][0]->setStyleSheet("QLabel {background-color: green;}");
    labels[0][0]->setText(QString::number(++count));
    currentY = 0;
    currentX = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkLabel(QString text)
{
    if(text == "0")
    {
        return true;
    }

    return false;
}

bool MainWindow::checkCell(int y, int x)
{
    if((y >= 0 && y < 4) && (x >=0 && x < 4))
    {

    }
    return false;
}


void MainWindow::on_pushButton_clicked()
{
    int i = qrand() % 4;
    int j = qrand() % 4;
    qDebug() << i << " " << j;
    if(checkLabel(labels[i][j]->text()))
    {
        labels[i][j]->setStyleSheet("QLabel {background-color: green;}");
        labels[i][j]->setText(QString::number(++count));
    }

}

