#pragma once

#include "test_impl.hpp"

class TestGstWebrtcRecv: public TestImpl
{
public:
    TestGstWebrtcRecv(int peer_id);

    ~TestGstWebrtcRecv();
protected:
    virtual void run() override;
    int peer_id_;

};


