#include "bird.h"
#include<QDebug>
#include<QGraphicsEffect>
#include<QPainter>
bird::bird()
{
    this->
}

bird::~bird()
{
    qDebug()<<"bird destructor";
}

void bird::start()
{
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(up()));
    timer->start(5);
}

int bird::get_x()
{
    return pos_x;
}

int bird::get_y()
{
    return pos_y;
}

void bird::set_x(int pos)
{
    pos_x=pos;
}

void bird::set_y(int pos)
{
    pos_y=pos;
}

void bird::up()
{
    if (pos().y()>=900)
    {
        emit end();
        qDebug()<<"you lose";
        QMessageBox msg;
        msg.setText("lose");
        msg.exec();

    }

        setY(pos().y()+1);
        set_y(pos().y());
        qDebug()<<"bird x : "<<pos().x();
        qDebug()<<"bird y : "<<pos().y();

}

void bird::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up)
    {
        setY(pos().y()-100);
        set_y(pos().y());
    }
}
int bird::pos_x=0;
int bird::pos_y=0;
