/****************************************************************************
** Meta object code from reading C++ file 'GameCells.h'
**
** Created: Mon Nov 7 23:43:49 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tic-tac-toe_Qt_2/GameCells.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameCells.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameCells[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameCells[] = {
    "GameCells\0\0gameCellClicked()\0"
    "slotgameCellClicked()\0"
};

const QMetaObject GameCells::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_GameCells,
      qt_meta_data_GameCells, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameCells::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameCells::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameCells::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameCells))
        return static_cast<void*>(const_cast< GameCells*>(this));
    return QLabel::qt_metacast(_clname);
}

int GameCells::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gameCellClicked(); break;
        case 1: slotgameCellClicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GameCells::gameCellClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
