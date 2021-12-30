#pragma once

#include <string>
#include <functional>
#include <tuple>

class TestInterface
{
public:
    using OnShowArgsType = std::tuple<const uint8_t *, int , int>;

    using OnShowFuncType = std::function<void(OnShowArgsType)>;

    using OnCtrlFuncType = std::function<void(void)>;

    virtual ~TestInterface() = default;

    virtual void start(const std::string&url) = 0;

    virtual void ctrl() = 0;

    virtual void stop() = 0;

    virtual void on_show(OnShowFuncType) = 0;

    virtual void on_ctrl(OnCtrlFuncType) = 0;


};
