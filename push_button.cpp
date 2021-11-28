#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QTimer>
#include <iostream>


class ImageButton : public QPushButton
{
  Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);

    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;
public slots:
    void setUp();
    void setDown();
private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;

};

ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setToolTip("Stop");
    QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    mButtonUpPixmap = QPixmap("C:\\Users\\Poizone\\CLionProjects\\untitled7\\stars\\red_star.png");
    mButtonDownPixmap = QPixmap("C:\\Users\\Poizone\\CLionProjects\\untitled7\\stars\\green_star.png");
    mCurrentButtonPixmap = mButtonUpPixmap;

    setGeometry(mCurrentButtonPixmap.rect());

    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);

}

void ImageButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const
{
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e)
{
    setDown();
}

void ImageButton::setDown()
{
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();

    QTimer::singleShot(500, this, &ImageButton::setUp);
}

void ImageButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    ImageButton red_button(nullptr);
    red_button.setFixedSize(200,200);
    red_button.move(1000, 600);
    QObject::connect(&red_button, &QPushButton::clicked, [](){std::cout<<"clicked\n";});
    red_button.show();

    return app.exec();

}

#include <push_button.moc>

