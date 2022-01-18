#include "widget.hpp"
#include "ui_widget.h"

#include <QFileDialog>
#include <QDebug>
#include <QImage>

#include "test_impl.hpp"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    test_ = std::make_shared<TestImpl>();
}

Widget::~Widget()
{
    on_btn_stop_clicked();
    delete ui;
}

void Widget::on_btn_browser_clicked()
{
    qDebug() << __FUNCTION__;
    url_ = QFileDialog::getOpenFileName(
                this,
                tr("open a file."),
                ".",
                tr("All files(*.*)"));
}

void Widget::on_btn_start_clicked()
{
    qDebug() << __FUNCTION__;
    test_->start(url_.toStdString());
}

void Widget::on_btn_ctrl_clicked()
{
    qDebug() << __FUNCTION__;
    test_->ctrl();
    test_->on_ctrl([this]{
       emit this->ui->btn_display->clicked();
    });

}

void Widget::on_btn_display_clicked()
{
    qDebug() << __FUNCTION__;
    test_->on_show([this](TestInterface::OnShowArgsType args){
        this->pic_show(std::get<0>(args),std::get<1>(args),std::get<2>(args));
    });
}

void Widget::on_btn_stop_clicked()
{
    qDebug() << __FUNCTION__;
    test_->stop();
}

void Widget::pic_show(const uint8_t *data, int width, int height)
{
    qDebug() << __FUNCTION__;
    QImage image(data,width,height,QImage::Format::Format_RGBA8888);
    ui->lab_display->resize(320,240);
    ui->lab_display->setPixmap(QPixmap::fromImage(image).scaled( ui->lab_display->size()));
    ui->lab_display->show();
}



