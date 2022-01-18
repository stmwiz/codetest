INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

message(  $$PWD )

#webrtc
WEBRTC_ROOT_DIR = /home/x/work/code/webrtc/build/webrtc_checkout/src
#WEBRTC_ROOT_DIR = /home/x/work/code/webrtc/webrtc-checkout/src
INCLUDEPATH     +=  $$WEBRTC_ROOT_DIR
LIBS            +=  -L$$WEBRTC_ROOT_DIR/out/Default/obj -lwebrtc
LIBS            +=  -L/usr/lib -ldl -lglib-2.0 -lc++
LIBS            +=  -L/usr/lib/x86_64-linux-gnu -ldl -lglib-2.0 -lc++

HEADERS += \
    $$PWD/webrtc_head.hpp
