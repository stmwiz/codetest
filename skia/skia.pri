INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

message(  $$PWD )

skia
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

HEADERS += \
    $$PWD/skhead.hpp \
    $$PWD/test_skia.hpp

SOURCES += \
    $$PWD/test_skia.cpp
