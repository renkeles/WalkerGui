#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QVector>
#include <QLabel>
#include <QDebug>
#include <QRandomGenerator>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QLabel* labels[4][4];
    bool checkList[4][4];

    Ui::MainWindow *ui;
    int count;
    int currentY;
    int currentX;
    int nextY;
    int nextX;
    QString tmpText;

    struct Cell{int y; int x;};
    QVector<Cell> tmpCells;

    bool checkCell(int, int);
    bool voidCheckCell(int, int);

    void initCheckList();
};
#endif // MAINWINDOW_H
