QT       += core gui
QT       += sql
QT       +=network
QT += core gui charts
QT       += core gui multimedia
#QT += androidextras
QT       += axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_goods.cpp \
    audio.cpp \
    bar_chart.cpp \
    cargo_sale.cpp \
    charts_manage.cpp \
    chat.cpp \
    chat2.cpp \
    custom_manage.cpp \
    database.cpp \
    entity.cpp \
    find_password.cpp \
    first_page.cpp \
    friend_list.cpp \
    friends_chat.cpp \
    goods_manage.cpp \
    http.cpp \
    input_cargo.cpp \
    main.cpp \
    login.cpp \
    notebook.cpp \
    pie_chart.cpp \
    point_chart.cpp \
    poiyline_chart.cpp \
    profit.cpp \
    qu_chart_real.cpp \
    qu_line.cpp \
    register.cpp \
    sale_chat.cpp \
    sale_goods.cpp \
    sale_manage.cpp \
    saleuser_first_page.cpp \
    speech.cpp \
    supplier_manage.cpp \
    supply_system.cpp \
    update_cargo.cpp \
    update_goods.cpp \
    widget.cpp

HEADERS += \
    add_goods.h \
    audio.h \
    bar_chart.h \
    cargo_sale.h \
    charts_manage.h \
    chat.h \
    chat2.h \
    custom_manage.h \
    database.h \
    entity.h \
    find_password.h \
    first_page.h \
    friend_list.h \
    friends_chat.h \
    goods_manage.h \
    goods_manage.h \
    http.h \
    input_cargo.h \
    login.h \
    notebook.h \
    pie_chart.h \
    point_chart.h \
    poiyline_chart.h \
    profit.h \
    qu_chart_real.h \
    qu_line.h \
    register.h \
    sale_chat.h \
    sale_goods.h \
    sale_manage.h \
    saleuser_first_page.h \
    speech.h \
    supplier_manage.h \
    supply_system.h \
    update_cargo.h \
    update_goods.h \
    widget.h

FORMS += \
    add_goods.ui \
    bar_chart.ui \
    cargo_sale.ui \
    charts_manage.ui \
    chat.ui \
    chat2.ui \
    custom_manage.ui \
    find_password.ui \
    first_page.ui \
    friend_list.ui \
    friends_chat.ui \
    goods_manage.ui \
    input_cargo.ui \
    login.ui \
    notebook.ui \
    pie_chart.ui \
    point_chart.ui \
    poiyline_chart.ui \
    profit.ui \
    qu_chart_real.ui \
    qu_line.ui \
    register.ui \
    sale_chat.ui \
    sale_goods.ui \
    sale_manage.ui \
    saleuser_first_page.ui \
    supplier_manage.ui \
    supply_system.ui \
    update_cargo.ui \
    update_goods.ui \
    widget.ui
#CONFIG += mobility
#MOBILITY =
#android{
#    data.files += aaa/qtDb.db
#    data.path = /assets/bbb
#    INSTALLS += data
#}
#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/aaa
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc
