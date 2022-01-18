#include "test_impl.hpp"

#include "head.hpp"
#include "test_impl.hpp"

TestImpl::TestImpl()
{

}

TestImpl::~TestImpl()
{
    TestImpl::stop();
}

void TestImpl::start(const std::string&url)
{
    url_ = url;

    if(!thread_.joinable()) {
        thread_ = std::thread( &TestImpl::run,this);
    }
}

void TestImpl::ctrl()
{

}

void TestImpl::stop()
{
    if(thread_.joinable()){
        quit_ = true;
        thread_.join();
        quit_ = false;
    }
}

void TestImpl::run()
{
}

