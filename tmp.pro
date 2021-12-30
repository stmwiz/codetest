QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
DEFINES += __STDC_CONSTANT_MACROS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    test_impl.cpp \
    test_skia.cpp \
    widget.cpp

HEADERS += \
    head.hpp \
    test_impl.hpp \
    test_interface.hpp \
    test_skia.hpp \
    widget.hpp

FORMS += \
    widget.ui

#ffmpeg

#FFMPEG_ROOT_DIR = /usr
FFMPEG_ROOT_DIR = /usr/local/
INCLUDEPATH     +=  $$FFMPEG_ROOT_DIR/include
LIBS            +=  -L$$FFMPEG_ROOT_DIR/lib -lavcodec -lavdevice -lavfilter -lavformat -lavutil  -lpostproc -lswscale

#webrtc
#WEBRTC_ROOT_DIR = /home/x/work/code/webrtc/build/webrtc_checkout/src
WEBRTC_ROOT_DIR = /home/x/work/code/webrtc/webrtc-checkout/src
INCLUDEPATH     +=  $$WEBRTC_ROOT_DIR
LIBS            +=  -L$$WEBRTC_ROOT_DIR/out/Default/obj -lwebrtc
#LIBS            +=  -L/usr/lib -ldl -lglib-2.0 -lc++
LIBS            +=  -L/usr/lib/x86_64-linux-gnu -ldl -lglib-2.0 -lc++

#skia
SKIA_ROOT_DIR = /home/x/work/code/skia_dir/build/skia
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/android
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/atlastext
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/c
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/codec
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/config
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/core
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/docs
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/effects
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/encode
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/gpu
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/pathops
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/private
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/svg
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/third_party
INCLUDEPATH     +=  $$SKIA_ROOT_DIR/include/utils

LIBS            +=  -L$$SKIA_ROOT_DIR/out/linux_clang -lskia


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
