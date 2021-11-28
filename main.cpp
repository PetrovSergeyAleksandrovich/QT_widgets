#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <iostream>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    auto *slider = new QSlider(Qt::Horizontal);
    auto *spinbox = new QSpinBox();

    slider->setMinimum(0);
    slider->setMaximum(100);

    spinbox->setMinimum(0);
    spinbox->setMaximum(100);

    QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
    QObject::connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), slider, &QSlider::setValue);

    slider->resize(300,50);
    spinbox->resize(100,50);
    slider->move(900, 500);
    spinbox->move(800, 500);

    slider->show();
    spinbox->show();

    app.exec();
    return 0;
}

#include <main.moc>
