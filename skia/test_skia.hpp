#pragma once

#include "test_impl.hpp"
#include "skhead.hpp"

class TestSkia : public TestImpl
{
public:
    TestSkia();

    virtual ~TestSkia();

    virtual void start(const std::string&url) override;

    virtual void ctrl() override;

    virtual void stop() override;

    virtual void on_show(OnShowFuncType) override;

    virtual void on_ctrl(OnCtrlFuncType) override;

private:

    void run () override;

private:
    OnShowArgsType on_show_args_{};
    OnCtrlFuncType on_ctrl_func_{};
    SkBitmap bitmap_{};
    std::unique_ptr<SkCodec> codec_{};
};

