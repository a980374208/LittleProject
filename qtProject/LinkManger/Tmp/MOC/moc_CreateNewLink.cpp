/****************************************************************************
** Meta object code from reading C++ file 'CreateNewLink.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../UI/CreateNewLink.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateNewLink.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CreateNewLink_t {
    QByteArrayData data[24];
    char stringdata0[335];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateNewLink_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateNewLink_t qt_meta_stringdata_CreateNewLink = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CreateNewLink"
QT_MOC_LITERAL(1, 14, 15), // "sig_updateModel"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 34), // "on_linkTypeCom_currentIndexCh..."
QT_MOC_LITERAL(4, 66, 4), // "arg1"
QT_MOC_LITERAL(5, 71, 33), // "on_linkFunCom_currentIndexCha..."
QT_MOC_LITERAL(6, 105, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(7, 125, 11), // "getLinkType"
QT_MOC_LITERAL(8, 137, 8), // "LinkType"
QT_MOC_LITERAL(9, 146, 8), // "linktype"
QT_MOC_LITERAL(10, 155, 11), // "getLinkFunc"
QT_MOC_LITERAL(11, 167, 12), // "LinkFunction"
QT_MOC_LITERAL(12, 180, 13), // "isMatchIPInfo"
QT_MOC_LITERAL(13, 194, 17), // "const BaseConfig*"
QT_MOC_LITERAL(14, 212, 10), // "socketInfo"
QT_MOC_LITERAL(15, 223, 3), // "fun"
QT_MOC_LITERAL(16, 227, 13), // "setBaseConfig"
QT_MOC_LITERAL(17, 241, 11), // "BaseConfig*"
QT_MOC_LITERAL(18, 253, 6), // "config"
QT_MOC_LITERAL(19, 260, 8), // "linkFunc"
QT_MOC_LITERAL(20, 269, 8), // "linkType"
QT_MOC_LITERAL(21, 278, 9), // "topicName"
QT_MOC_LITERAL(22, 288, 23), // "on_cancleButton_clicked"
QT_MOC_LITERAL(23, 312, 22) // "on_closeButton_clicked"

    },
    "CreateNewLink\0sig_updateModel\0\0"
    "on_linkTypeCom_currentIndexChanged\0"
    "arg1\0on_linkFunCom_currentIndexChanged\0"
    "on_okButton_clicked\0getLinkType\0"
    "LinkType\0linktype\0getLinkFunc\0"
    "LinkFunction\0isMatchIPInfo\0const BaseConfig*\0"
    "socketInfo\0fun\0setBaseConfig\0BaseConfig*\0"
    "config\0linkFunc\0linkType\0topicName\0"
    "on_cancleButton_clicked\0on_closeButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateNewLink[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   65,    2, 0x08 /* Private */,
       5,    1,   68,    2, 0x08 /* Private */,
       6,    0,   71,    2, 0x08 /* Private */,
       7,    1,   72,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,
      12,    2,   78,    2, 0x08 /* Private */,
      16,    4,   83,    2, 0x08 /* Private */,
      22,    0,   92,    2, 0x08 /* Private */,
      23,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    0x80000000 | 8, QMetaType::QString,    9,
    0x80000000 | 11, QMetaType::QString,    9,
    QMetaType::Bool, 0x80000000 | 13, 0x80000000 | 11,   14,   15,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 11, 0x80000000 | 8, QMetaType::QStringList,   18,   19,   20,   21,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateNewLink::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CreateNewLink *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_updateModel(); break;
        case 1: _t->on_linkTypeCom_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_linkFunCom_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_okButton_clicked(); break;
        case 4: { LinkType _r = _t->getLinkType((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< LinkType*>(_a[0]) = std::move(_r); }  break;
        case 5: { LinkFunction _r = _t->getLinkFunc((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< LinkFunction*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->isMatchIPInfo((*reinterpret_cast< const BaseConfig*(*)>(_a[1])),(*reinterpret_cast< LinkFunction(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setBaseConfig((*reinterpret_cast< BaseConfig*(*)>(_a[1])),(*reinterpret_cast< const LinkFunction(*)>(_a[2])),(*reinterpret_cast< const LinkType(*)>(_a[3])),(*reinterpret_cast< const QStringList(*)>(_a[4]))); break;
        case 8: _t->on_cancleButton_clicked(); break;
        case 9: _t->on_closeButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CreateNewLink::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CreateNewLink::sig_updateModel)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CreateNewLink::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CreateNewLink.data,
    qt_meta_data_CreateNewLink,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CreateNewLink::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateNewLink::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CreateNewLink.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CreateNewLink::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void CreateNewLink::sig_updateModel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
