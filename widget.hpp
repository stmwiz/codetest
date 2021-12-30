#pragma once

#include <QWidget>
#include <memory>

#include "test_interface.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btn_browser_clicked();

    void on_btn_start_clicked();

    void on_btn_ctrl_clicked();

    void on_btn_display_clicked();

    void on_btn_stop_clicked();

    void pic_show(const uchar *data, int width, int height);

private:
    const QString open_file_browser();

private:
    Ui::Widget *ui;

    std::shared_ptr<TestInterface> test_ = nullptr;

    QString url_;
};
