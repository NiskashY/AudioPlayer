/****************************************************************************
** Meta object code from reading C++ file 'mainpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/mainpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainPage_t {
    QByteArrayData data[13];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainPage_t qt_meta_stringdata_MainPage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainPage"
QT_MOC_LITERAL(1, 9, 19), // "on_backLogo_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 30), // "on_addFromDeviceButton_clicked"
QT_MOC_LITERAL(4, 61, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(5, 88, 5), // "index"
QT_MOC_LITERAL(6, 94, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(7, 117, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(8, 139, 21), // "on_prevButton_clicked"
QT_MOC_LITERAL(9, 161, 24), // "on_shuffleButton_clicked"
QT_MOC_LITERAL(10, 186, 23), // "on_repeatButton_clicked"
QT_MOC_LITERAL(11, 210, 8), // "PlaySong"
QT_MOC_LITERAL(12, 219, 20) // "SetMaxSliderDuration"

    },
    "MainPage\0on_backLogo_clicked\0\0"
    "on_addFromDeviceButton_clicked\0"
    "on_tabWidget_tabBarClicked\0index\0"
    "on_pauseButton_clicked\0on_nextButton_clicked\0"
    "on_prevButton_clicked\0on_shuffleButton_clicked\0"
    "on_repeatButton_clicked\0PlaySong\0"
    "SetMaxSliderDuration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    1,   66,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainPage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_backLogo_clicked(); break;
        case 1: _t->on_addFromDeviceButton_clicked(); break;
        case 2: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pauseButton_clicked(); break;
        case 4: _t->on_nextButton_clicked(); break;
        case 5: _t->on_prevButton_clicked(); break;
        case 6: _t->on_shuffleButton_clicked(); break;
        case 7: _t->on_repeatButton_clicked(); break;
        case 8: _t->PlaySong(); break;
        case 9: _t->SetMaxSliderDuration(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_MainPage.data,
    qt_meta_data_MainPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainPage.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MainPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
