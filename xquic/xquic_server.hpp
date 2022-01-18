#pragma once

#include "test_impl.hpp"


class XQuicServer: public TestImpl
{
public:
    XQuicServer();

    ~XQuicServer();
protected:
    virtual void run() override;

};

