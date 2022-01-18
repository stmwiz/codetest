#pragma once

#include "test_impl.hpp"

class XQuicClient: public TestImpl
{
public:
    XQuicClient();

    ~XQuicClient();
protected:
    virtual void run() override;

};

