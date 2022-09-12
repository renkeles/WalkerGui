#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    initCheckList();
    currentY = 0;
    currentX = 0;


    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            labels[i][j]->setText(QString::number(count));
            labels[i][j]->setStyleSheet("QLabel {background-color: yellow;}");
        }

    }

    labels[currentY][currentX]->setStyleSheet("QLabel {background-color: green;}");
    labels[currentY][currentX]->setText(QString::number(++count));

    checkList[currentY][currentX] = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkCell(int y, int x)
{
    if((y >= 0 && y < 4) && (x >=0 && x < 4))
    {
        return true;
    }
    return false;
}

bool MainWindow::voidCheckCell(int y, int x)
{
    if(checkList[y][x])
    {
        return true;
    }
    return false;
}

void MainWindow::initCheckList()
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            checkList[i][j] = true;
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    /*
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            qDebug() << "[" << i << "][" << j << "]" << checkList[i][j];
        }
    }
    */

    for(int i = 0; i < 1; ++i)
    //while(count < 2)
    {
        //int y = QRandomGenerator::global()->bounded(0,4);
        //qDebug() << y << " " << x;
        if(checkCell(currentY - 1, currentX))
        {
            if(voidCheckCell(currentY - 1, currentX))
            {
               qDebug() << "Up step";
            }
        }
        if(checkCell(currentY + 1, currentX))
        {
            if(voidCheckCell(currentY + 1, currentX))
            {
               qDebug() << "Down step";
            }
        }
        if(checkCell(currentY, currentX - 1))
        {
            if(voidCheckCell(currentY, currentX - 1))
            {
               qDebug() << "Left step";
            }
        }
        if(checkCell(currentY, currentX + 1))
        {
            if(voidCheckCell(currentY, currentX + 1))
            {
               qDebug() << "Right step";
            }
        }

    }


}


void MainWindow::on_pushButton_2_clicked()
{
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
}

