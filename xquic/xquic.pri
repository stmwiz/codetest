INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

message(  $$PWD )

HEADERS += \
    $$PWD/xquic_head.hpp

DISTFILES += \
    $$PWD/xquic.txt


INCLUDEPATH += $$PWD/xquic/include

LIBS += -L$$PWD/xquic/ -lcrypto -lssl -lxquic-static
