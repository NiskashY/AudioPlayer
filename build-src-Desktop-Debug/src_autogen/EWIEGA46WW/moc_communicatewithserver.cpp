/****************************************************************************
** Meta object code from reading C++ file 'communicatewithserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/communicatewithserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communicatewithserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommunicateWithServer_t {
    QByteArrayData data[11];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommunicateWithServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommunicateWithServer_t qt_meta_stringdata_CommunicateWithServer = {
    {
QT_MOC_LITERAL(0, 0, 21), // "CommunicateWithServer"
QT_MOC_LITERAL(1, 22, 9), // "sockReady"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "sockDisc"
QT_MOC_LITERAL(4, 42, 12), // "CheckAccount"
QT_MOC_LITERAL(5, 55, 21), // "QPair<bool,Existance>"
QT_MOC_LITERAL(6, 77, 13), // "CreateAccount"
QT_MOC_LITERAL(7, 91, 18), // "GetUserLikedTracks"
QT_MOC_LITERAL(8, 110, 21), // "GetFilePathFromServer"
QT_MOC_LITERAL(9, 132, 8), // "dir_path"
QT_MOC_LITERAL(10, 141, 11) // "UploadFiles"

    },
    "CommunicateWithServer\0sockReady\0\0"
    "sockDisc\0CheckAccount\0QPair<bool,Existance>\0"
    "CreateAccount\0GetUserLikedTracks\0"
    "GetFilePathFromServer\0dir_path\0"
    "UploadFiles"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommunicateWithServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    2,   56,    2, 0x0a /* Public */,
       6,    2,   61,    2, 0x0a /* Public */,
       7,    1,   66,    2, 0x0a /* Public */,
       8,    2,   69,    2, 0x0a /* Public */,
       8,    1,   74,    2, 0x2a /* Public | MethodCloned */,
      10,    2,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 5, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::QStringList, QMetaType::QString,    2,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    9,
    QMetaType::QString, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QStringList, QMetaType::QString,    2,    2,

       0        // eod
};

void CommunicateWithServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommunicateWithServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sockReady(); break;
        case 1: _t->sockDisc(); break;
        case 2: { QPair<bool,Existance> _r = _t->CheckAccount((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPair<bool,Existance>*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->CreateAccount((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: { QStringList _r = _t->GetUserLikedTracks((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->GetFilePathFromServer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->GetFilePathFromServer((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->UploadFiles((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommunicateWithServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CommunicateWithServer.data,
    qt_meta_data_CommunicateWithServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommunicateWithServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommunicateWithServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommunicateWithServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CommunicateWithServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
