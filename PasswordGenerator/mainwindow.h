#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void generatePassword();
    void clearHistory();

private:
    QLineEdit* lengthInput;
    QPushButton* generateButton;
    QPushButton* clearButton;
    QLabel* passwordDisplay;
    QListWidget* historyList;

    QString generateRandomPassword(int length);
};

#endif // MAINWINDOW_H
