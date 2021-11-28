#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QImage>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QTimer>
#include <iostream>

class Image : public QPushButton
{
    Q_OBJECT
private:
    QPixmap mCurrentImage;
    QPixmap mRedImage;
    QPixmap mGreenImage;
    QPixmap mYellowImage;
    QPixmap mBlueImage;
public:
    Image() = default;
    Image(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
public slots:
    void setRed();
    void setGreen();
    void setYellow();
    void setBlue();
    void changeColor(int newValue);
};

Image::Image(QWidget *parent)
{
    setParent(parent);

    setToolTip("Stop");
    QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    mRedImage = QPixmap("C:\\Users\\Poizone\\CLionProjects\\untitled7\\stars\\red_star.png");
    mGreenImage = QPixmap("C:\\Users\\Poizone\\CLionProjects\\untitled7\\stars\\green_star.png");
    mYellowImage = QPixmap("C:\\Users\\Poizone\\CLionProjects\\untitled7\\stars\\yellow_star.png");
    mBlueImage = QPixmap("C:\\Users\\Poizone\\CLionProjects\\untitled7\\stars\\blue_star.png");
    mCurrentImage = mBlueImage;
    setGeometry(mCurrentImage.rect());
}

void Image::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentImage);
}

void Image::setRed()
{
    mCurrentImage = mRedImage;
    update();
}

void Image::setGreen()
{
    mCurrentImage = mGreenImage;
    update();
}

void Image::setYellow()
{
    mCurrentImage = mYellowImage;
    update();
}

void Image::setBlue()
{
    mCurrentImage = mBlueImage;
    update();
}

void Image::changeColor(int newValue)
{
    if(newValue <= 25)
    {
        setRed();
    }
    else if (newValue > 25 && newValue <= 50)
    {
        setGreen();
    }
    else if (newValue > 50 && newValue <= 75)
    {
        setYellow();
    }
    else if (newValue > 75)
    {
        setBlue();
    }
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Image star(nullptr);

    auto *slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);

    auto *layout = new QGridLayout(&star);
    layout->addWidget(slider);

    star.setFixedSize(200,200);
    star.move(1000, 600);

    QObject::connect(slider, &QSlider::valueChanged, &star, &Image::changeColor);

    star.show();

    return app.exec();
}

#include <colors.moc>