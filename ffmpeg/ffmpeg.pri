INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

message(  $$PWD )

#ffmpeg
DEFINES += __STDC_CONSTANT_MACROS
FFMPEG_ROOT_DIR = /usr
#FFMPEG_ROOT_DIR = /usr/local/
INCLUDEPATH     +=  $$FFMPEG_ROOT_DIR/include
LIBS            +=  -L$$FFMPEG_ROOT_DIR/lib -lavcodec -lavdevice -lavfilter -lavformat -lavutil  -lpostproc -lswscale

HEADERS += \
    $$PWD/ffhead.hpp
