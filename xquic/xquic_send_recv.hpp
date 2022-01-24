#pragma once

#include <stdio.h>
#include <errno.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <event2/event.h>
#include <inttypes.h>
#include <net/if.h>

#include <xquic/xquic.h>
#include <xquic/xquic_typedef.h>
#include <xquic/xqc_errno.h>
#include <xquic/xqc_http3.h>

#include "test_impl.hpp"


class XQuicSR:public TestImpl
{
public:
    explicit XQuicSR();

    ~XQuicSR();

protected:
    virtual void run() override;
};

