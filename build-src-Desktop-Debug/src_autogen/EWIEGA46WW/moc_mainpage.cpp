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
    QByteArrayData data[19];
    char stringdata0[377];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainPage_t qt_meta_stringdata_MainPage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainPage"
QT_MOC_LITERAL(1, 9, 28), // "on_exitAccountButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 30), // "on_addFromDeviceButton_clicked"
QT_MOC_LITERAL(4, 70, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(5, 97, 5), // "index"
QT_MOC_LITERAL(6, 103, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(7, 126, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(8, 148, 21), // "on_prevButton_clicked"
QT_MOC_LITERAL(9, 170, 24), // "on_shuffleButton_clicked"
QT_MOC_LITERAL(10, 195, 23), // "on_repeatButton_clicked"
QT_MOC_LITERAL(11, 219, 8), // "PlaySong"
QT_MOC_LITERAL(12, 228, 24), // "SetCurrentSliderPosition"
QT_MOC_LITERAL(13, 253, 20), // "SetMaxSliderPosition"
QT_MOC_LITERAL(14, 274, 16), // "SetSongNameLabel"
QT_MOC_LITERAL(15, 291, 19), // "SliderPositionMoved"
QT_MOC_LITERAL(16, 311, 26), // "on_changeDirButton_clicked"
QT_MOC_LITERAL(17, 338, 29), // "on_verticalSlider_sliderMoved"
QT_MOC_LITERAL(18, 368, 8) // "position"

    },
    "MainPage\0on_exitAccountButton_clicked\0"
    "\0on_addFromDeviceButton_clicked\0"
    "on_tabWidget_tabBarClicked\0index\0"
    "on_pauseButton_clicked\0on_nextButton_clicked\0"
    "on_prevButton_clicked\0on_shuffleButton_clicked\0"
    "on_repeatButton_clicked\0PlaySong\0"
    "SetCurrentSliderPosition\0SetMaxSliderPosition\0"
    "SetSongNameLabel\0SliderPositionMoved\0"
    "on_changeDirButton_clicked\0"
    "on_verticalSlider_sliderMoved\0position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       6,    0,   94,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    1,  105,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void MainPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainPage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_exitAccountButton_clicked(); break;
        case 1: _t->on_addFromDeviceButton_clicked(); break;
        case 2: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pauseButton_clicked(); break;
        case 4: _t->on_nextButton_clicked(); break;
        case 5: _t->on_prevButton_clicked(); break;
        case 6: _t->on_shuffleButton_clicked(); break;
        case 7: _t->on_repeatButton_clicked(); break;
        case 8: _t->PlaySong(); break;
        case 9: _t->SetCurrentSliderPosition(); break;
        case 10: _t->SetMaxSliderPosition(); break;
        case 11: _t->SetSongNameLabel(); break;
        case 12: _t->SliderPositionMoved(); break;
        case 13: _t->on_changeDirButton_clicked(); break;
        case 14: _t->on_verticalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
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
    return QMainWindow::qt_metacast(_clname);
}

int MainPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
