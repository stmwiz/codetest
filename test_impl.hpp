#pragma once

#include <string>
#include <thread>
#include <mutex>
#include <atomic>

#include "test_interface.hpp"

class TestImpl : public TestInterface
{
public:
    TestImpl();

    virtual ~TestImpl();

    virtual void start(const std::string&url) override;

    virtual void ctrl() override;

    virtual void stop() override;

    virtual void on_show(OnShowFuncType) override {};

    virtual void on_ctrl(OnCtrlFuncType) override {};

protected:
    virtual void run();

protected:
    std::string url_;
    std::atomic<bool> quit_ = false;
private:
    std::mutex mutex_thread_;
    std::thread thread_;
};

