INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

message(  $$PWD )

DEFINS +=

HEADERS += \
    $$PWD/xquic_client.hpp \
    $$PWD/xquic_head.hpp \
    $$PWD/xquic_server.hpp

DISTFILES += \
    $$PWD/xquic.txt


INCLUDEPATH += $$PWD/xquic/include

LIBS += -L$$PWD/xquic/ -lxquic-static -lssl  -lcrypto
LIBS += -levent -lgcov -lm -ldl

SOURCES += \
    $$PWD/xquic_client.cpp \
    $$PWD/xquic_server.cpp
