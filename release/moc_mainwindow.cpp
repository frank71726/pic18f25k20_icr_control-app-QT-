/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata[386];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 15),
QT_MOC_LITERAL(4, 43, 5),
QT_MOC_LITERAL(5, 49, 9),
QT_MOC_LITERAL(6, 59, 4),
QT_MOC_LITERAL(7, 64, 8),
QT_MOC_LITERAL(8, 73, 11),
QT_MOC_LITERAL(9, 85, 28),
QT_MOC_LITERAL(10, 114, 5),
QT_MOC_LITERAL(11, 120, 21),
QT_MOC_LITERAL(12, 142, 21),
QT_MOC_LITERAL(13, 164, 19),
QT_MOC_LITERAL(14, 184, 7),
QT_MOC_LITERAL(15, 192, 19),
QT_MOC_LITERAL(16, 212, 20),
QT_MOC_LITERAL(17, 233, 20),
QT_MOC_LITERAL(18, 254, 21),
QT_MOC_LITERAL(19, 276, 28),
QT_MOC_LITERAL(20, 305, 5),
QT_MOC_LITERAL(21, 311, 27),
QT_MOC_LITERAL(22, 339, 4),
QT_MOC_LITERAL(23, 344, 20),
QT_MOC_LITERAL(24, 365, 20)
    },
    "MainWindow\0openSerialPort\0\0closeSerialPort\0"
    "about\0writeData\0data\0readData\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "on_but_start_released\0on_but_reset_released\0"
    "on_all_test_clicked\0checked\0"
    "on_degree_0_clicked\0on_degree_90_pressed\0"
    "on_degree_90_clicked\0on_degree_180_clicked\0"
    "on_voltage_dial_valueChanged\0value\0"
    "on_voltage_Box_valueChanged\0arg1\0"
    "on_but_auto_released\0on_but_stop_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    1,  102,    2, 0x08 /* Private */,
       7,    0,  105,    2, 0x08 /* Private */,
       8,    1,  106,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    1,  111,    2, 0x08 /* Private */,
      15,    1,  114,    2, 0x08 /* Private */,
      16,    0,  117,    2, 0x08 /* Private */,
      17,    1,  118,    2, 0x08 /* Private */,
      18,    1,  121,    2, 0x08 /* Private */,
      19,    1,  124,    2, 0x08 /* Private */,
      21,    1,  127,    2, 0x08 /* Private */,
      23,    0,  130,    2, 0x08 /* Private */,
      24,    0,  131,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->openSerialPort(); break;
        case 1: _t->closeSerialPort(); break;
        case 2: _t->about(); break;
        case 3: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->readData(); break;
        case 5: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 6: _t->on_but_start_released(); break;
        case 7: _t->on_but_reset_released(); break;
        case 8: _t->on_all_test_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_degree_0_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_degree_90_pressed(); break;
        case 11: _t->on_degree_90_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_degree_180_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_voltage_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_voltage_Box_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_but_auto_released(); break;
        case 16: _t->on_but_stop_released(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
