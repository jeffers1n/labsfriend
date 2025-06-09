#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *slidersLayout = new QHBoxLayout();

    healthSlider = createSlider();
    workSlider = createSlider();
    loveSlider = createSlider();
    friendsSlider = createSlider();
    hobbySlider = createSlider();

    slidersLayout->addWidget(new QLabel("Здоровье"));
    slidersLayout->addWidget(healthSlider);
    slidersLayout->addWidget(new QLabel("Работа"));
    slidersLayout->addWidget(workSlider);
    slidersLayout->addWidget(new QLabel("Личная жизнь"));
    slidersLayout->addWidget(loveSlider);
    slidersLayout->addWidget(new QLabel("Друзья"));
    slidersLayout->addWidget(friendsSlider);
    slidersLayout->addWidget(new QLabel("Хобби"));
    slidersLayout->addWidget(hobbySlider);

    QPushButton *calcButton = new QPushButton("Рассчитать");
    resultLabel = new QLabel("Нажмите 'Рассчитать', чтобы узнать уровень счастья");

    connect(calcButton, &QPushButton::clicked, this, &MainWindow::calculateHappiness);

    mainLayout->addLayout(slidersLayout);
    mainLayout->addWidget(calcButton);
    mainLayout->addWidget(resultLabel);
}

MainWindow::~MainWindow() {}

QSlider* MainWindow::createSlider() {
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(50);
    return slider;
}

void MainWindow::calculateHappiness() {
    int total = healthSlider->value() +
                workSlider->value() +
                loveSlider->value() +
                friendsSlider->value() +
                hobbySlider->value();

    int happiness = total / 5;

    QString comment;
    if (happiness >= 80) {
        comment = "Отличные новости! Вы очень счастливый человек!";
    } else if (happiness >= 60) {
        comment = "Вы на правильном пути!";
    } else if (happiness >= 40) {
        comment = "Вам стоит подумать над балансом в жизни.";
    } else {
        comment = "Попробуйте заняться любимым делом или поговорить с близкими.";
    }

    resultLabel->setText(QString("Уровень счастья: %1%\n%2").arg(happiness).arg(comment));
}

