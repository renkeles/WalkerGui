#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QVector>
#include <QLabel>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool checkLabel(QString);

private slots:
    void on_pushButton_clicked();

private:
    QLabel* labels[4][4];
    Ui::MainWindow *ui;
    int count;
};
#endif // MAINWINDOW_H
