/****************************************************************************
** Meta object code from reading C++ file 'slotscommunicationhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/checker/slotscommunicationhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'slotscommunicationhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SlotsCommunicationHandler_t {
    QByteArrayData data[11];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SlotsCommunicationHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SlotsCommunicationHandler_t qt_meta_stringdata_SlotsCommunicationHandler = {
    {
QT_MOC_LITERAL(0, 0, 25), // "SlotsCommunicationHandler"
QT_MOC_LITERAL(1, 26, 13), // "addConnection"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 14), // "const QObject*"
QT_MOC_LITERAL(4, 56, 6), // "sender"
QT_MOC_LITERAL(5, 63, 11), // "const char*"
QT_MOC_LITERAL(6, 75, 6), // "signal"
QT_MOC_LITERAL(7, 82, 8), // "receiver"
QT_MOC_LITERAL(8, 91, 6), // "method"
QT_MOC_LITERAL(9, 98, 18), // "Qt::ConnectionType"
QT_MOC_LITERAL(10, 117, 4) // "type"

    },
    "SlotsCommunicationHandler\0addConnection\0"
    "\0const QObject*\0sender\0const char*\0"
    "signal\0receiver\0method\0Qt::ConnectionType\0"
    "type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SlotsCommunicationHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    5,   24,    2, 0x0a /* Public */,
       1,    4,   35,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 9,    4,    6,    7,    8,   10,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 3, 0x80000000 | 5,    4,    6,    7,    8,

       0        // eod
};

void SlotsCommunicationHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SlotsCommunicationHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addConnection((*reinterpret_cast< const QObject*(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< const QObject*(*)>(_a[3])),(*reinterpret_cast< const char*(*)>(_a[4])),(*reinterpret_cast< Qt::ConnectionType(*)>(_a[5]))); break;
        case 1: _t->addConnection((*reinterpret_cast< const QObject*(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< const QObject*(*)>(_a[3])),(*reinterpret_cast< const char*(*)>(_a[4]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SlotsCommunicationHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SlotsCommunicationHandler.data,
    qt_meta_data_SlotsCommunicationHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SlotsCommunicationHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SlotsCommunicationHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SlotsCommunicationHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SlotsCommunicationHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
