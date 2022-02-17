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

    void on_btn_server_clicked();

    void on_btn_clinet_clicked();

    void on_btn_snd_rcv_clicked();

private:
    const QString open_file_browser();

private:
    Ui::Widget *ui;
    QString url_;
    std::shared_ptr<TestInterface> test_ = nullptr;
    std::shared_ptr<TestInterface> xquic_svr_ = nullptr;
    std::shared_ptr<TestInterface> xquic_cli_ = nullptr;
    std::shared_ptr<TestInterface> xquic_sr_ = nullptr;
    std::shared_ptr<TestInterface> gstwebrtc_sr_ = nullptr;
    std::shared_ptr<TestInterface> gstwebrtc_r_ = nullptr;

};
