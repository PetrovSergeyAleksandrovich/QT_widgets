#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHBoxLayout>

#include <iostream>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget();

    QPushButton *button1 = new QPushButton("one", window);
    QPushButton *button2 = new QPushButton("two", window);
    QPushButton *button3 = new QPushButton("three", window);
    QPushButton *button4 = new QPushButton("four", window);
    QPushButton *button5 = new QPushButton("five", window);

    ///Placing buttons manualy
    //button1->move(40, 50);
    //button2->move(140, 150);
    //button3->move(200, 200);

    ///Vertical Box layout window for buttons
//    auto *layout = new QVBoxLayout(window);
//    layout->addWidget(button1);
//    layout->addWidget(button2);
//    layout->addWidget(button3);
//    layout->addWidget(button4);
//    layout->addWidget(button5);

    ///GRID Box layout window for buttons
    auto *layout = new QGridLayout(window);
    layout->addWidget(button1, 0,0);
    layout->addWidget(button2, 0,1);
    layout->addWidget(button3, 1,0, 1,2);
    layout->addWidget(button4, 2,0);
    layout->addWidget(button5, 2,1);


    window->resize(300,300);
    window->move(1000,500);
    window->show();



    app.exec();
}

