#include "test_skia.hpp"

TestSkia::TestSkia():TestImpl()
{

}

TestSkia::~TestSkia()
{
    stop();
}

void TestSkia::start(const std::string &url)
{
    return TestImpl::start(url);
}

void TestSkia::ctrl()
{
    return TestImpl::ctrl();
}

void TestSkia::stop()
{
    return TestImpl::stop();
}

void TestSkia::on_show(OnShowFuncType show_func)
{
    show_func(on_show_args_);
    return TestImpl::on_show(show_func);
}

void TestSkia::on_ctrl(OnCtrlFuncType on_ctrl_func)
{
    on_ctrl_func_ = on_ctrl_func;
    return; TestImpl::on_ctrl(on_ctrl_func);
}

void TestSkia::run()
{

    auto data = SkData::MakeFromFileName(url_.c_str());
    codec_ = SkCodec::MakeFromData(std::move(data));
    auto count = codec_->getFrameCount();

    SkCodec::Options options;
    for(int i = 0;i < count && !quit_;i++){
        options.fFrameIndex = i;
        SkCodec::FrameInfo frame_info{};
        auto ret = codec_->getFrameInfo(i,&frame_info);
        const auto alphaType = kOpaque_SkAlphaType == frame_info.fAlphaType ?
                    kOpaque_SkAlphaType : kPremul_SkAlphaType;
        auto info = codec_->getInfo().makeAlphaType(alphaType);
        ret = bitmap_.tryAllocPixels(info);

        codec_->getPixels(bitmap_.info(),bitmap_.getPixels(),bitmap_.rowBytes(),&options);
        int64_t dur = frame_info.fDuration;
        on_show_args_ = std::make_tuple<const uint8_t *, int , int>((const uint8_t *)bitmap_.getPixels(),info.width(),info.height());
        on_ctrl_func_();
        bitmap_.notifyPixelsChanged();
        usleep(1000*dur);
    }


    return TestImpl::run();
}
