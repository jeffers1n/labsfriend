#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QChar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Элементы интерфейса
    lengthInput = new QLineEdit("12", this);
    generateButton = new QPushButton("Сгенерировать пароль", this);
    clearButton = new QPushButton("Очистить историю", this);
    passwordDisplay = new QLabel("Здесь будет пароль...", this);
    passwordDisplay->setStyleSheet("font-size: 16px; padding: 10px;");
    historyList = new QListWidget(this);
    historyList->setMinimumWidth(250);

    // Размещение элементов
    QHBoxLayout* inputLayout = new QHBoxLayout();
    inputLayout->addWidget(new QLabel("Длина пароля:"));
    inputLayout->addWidget(lengthInput);

    QVBoxLayout* leftLayout = new QVBoxLayout();
    leftLayout->addLayout(inputLayout);
    leftLayout->addWidget(generateButton);
    leftLayout->addWidget(passwordDisplay);
    leftLayout->addWidget(clearButton);

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(historyList);

    centralWidget->setLayout(mainLayout);

    // Обработчики событий
    connect(generateButton, &QPushButton::clicked, this, &MainWindow::generatePassword);
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearHistory);
}

MainWindow::~MainWindow() {}

void MainWindow::generatePassword() {
    bool ok;
    int length = lengthInput->text().toInt(&ok);

    if (!ok || length <= 0 || length > 100) {
        QMessageBox::warning(this, "Ошибка", "Введите корректную длину пароля (1–100).");
        return;
    }

    QString password = generateRandomPassword(length);
    passwordDisplay->setText(password);
    historyList->insertItem(0, password);
}

void MainWindow::clearHistory() {
    historyList->clear();
}

QString MainWindow::generateRandomPassword(int length) {
    const QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                          "abcdefghijklmnopqrstuvwxyz"
                          "0123456789";
    QString password;

    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(chars.length());
        password.append(chars.at(index));
    }

    return password;
}
