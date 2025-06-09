#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculateHappiness();

private:
    QSlider* createSlider();

    QSlider *healthSlider;
    QSlider *workSlider;
    QSlider *loveSlider;
    QSlider *friendsSlider;
    QSlider *hobbySlider;

    QLabel *resultLabel;
};

#endif // MAINWINDOW_H
