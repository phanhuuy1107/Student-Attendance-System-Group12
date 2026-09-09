#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Cac slot hung su kien click tu giao dien (Tram)
    void on_btnLogin_clicked();
    void on_btnSubmitCheckIn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H