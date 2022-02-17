INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

message(  $$PWD )

INCLUDEPATH += /usr/include
INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/include/gstreamer-1.0
INCLUDEPATH += /usr/include/sysprof-4
INCLUDEPATH += /usr/include/orc-0.4
INCLUDEPATH += /usr/include/libmount
INCLUDEPATH += /usr/include/blkid
INCLUDEPATH += /usr/include/libsoup-2.4
INCLUDEPATH += /usr/include/libxml2
INCLUDEPATH += /usr/include/json-glib-1.0
INCLUDEPATH += /usr/include/glib-2.0
INCLUDEPATH += /usr/lib/glib-2.0/include


#LIBS += -lgstreamer-1.0 -lgobject-2.0 -lglib-2.0 -l -lgstwebrtc-1.0 -lgstsdp-1.0 -lsoup-2.4 -ljson-glib-1.0

LIBS += -lgstreamer-1.0 -lgobject-2.0 -lglib-2.0 -lgstsdp-1.0 \
-lgstwebrtc-1.0 -lgstrtp-1.0 -lsoup-2.4 -ljson-glib-1.0 -lgmodule-2.0 \
-lm -ldl -lunwind -ldw -llzma -lpthread \
-lffi -lpcre -lgstpbutils-1.0 \
-lgio-2.0 -lgstbase-1.0 -lxml2 \
-lsqlite3 -lpsl -lbrotlidec \
-lgssapi_krb5 -lz -lelf \
-lzstd -lbz2 -lgstvideo-1.0 -lgstaudio-1.0 \
-lgsttag-1.0 -lmount -lresolv -licuuc \
-lidn2 -lbrotlicommon -lkrb5 -lk5crypto \
-lcom_err -lkrb5support -lkeyutils \
-lorc-0.4 -lblkid -licudata -lgcov


HEADERS += \
    $$PWD/test_gst_webrtc_recv.hpp \
    $$PWD/test_gst_webrtc_send_recv.hpp

SOURCES += \
    $$PWD/test_gst_webrtc_recv.cpp \
    $$PWD/test_gst_webrtc_send_recv.cpp
