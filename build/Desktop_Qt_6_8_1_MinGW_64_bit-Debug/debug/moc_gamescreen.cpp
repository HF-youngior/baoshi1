/****************************************************************************
** Meta object code from reading C++ file 'gamescreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gamescreen.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10GameScreenE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10GameScreenE = QtMocHelpers::stringData(
    "GameScreen",
    "gameEnded",
    "",
    "score",
    "returnToLogin",
    "resetPotionPurchased",
    "count",
    "freezePotionPurchased",
    "superPotionPurchased",
    "startCountdown",
    "pauseGame",
    "endGame",
    "on_shopButton_clicked",
    "on_exitButton_clicked",
    "onGemClicked",
    "row",
    "col",
    "on_resetButton_clicked",
    "resetBoard",
    "redealToGrid",
    "on_gameOverDialogAccepted",
    "on_gameOverDialogRejected",
    "on_resetPotionPurchased",
    "on_freezePotionPurchased",
    "on_superPotionPurchased"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10GameScreenE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  128,    2, 0x06,    1 /* Public */,
       4,    0,  131,    2, 0x06,    3 /* Public */,
       5,    1,  132,    2, 0x06,    4 /* Public */,
       7,    1,  135,    2, 0x06,    6 /* Public */,
       8,    1,  138,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,  141,    2, 0x0a,   10 /* Public */,
      10,    0,  142,    2, 0x0a,   11 /* Public */,
      11,    1,  143,    2, 0x0a,   12 /* Public */,
      12,    0,  146,    2, 0x08,   14 /* Private */,
      13,    0,  147,    2, 0x08,   15 /* Private */,
      14,    2,  148,    2, 0x08,   16 /* Private */,
      17,    0,  153,    2, 0x08,   19 /* Private */,
      18,    0,  154,    2, 0x08,   20 /* Private */,
      19,    0,  155,    2, 0x08,   21 /* Private */,
      20,    0,  156,    2, 0x08,   22 /* Private */,
      21,    0,  157,    2, 0x08,   23 /* Private */,
      22,    1,  158,    2, 0x08,   24 /* Private */,
      23,    1,  161,    2, 0x08,   26 /* Private */,
      24,    1,  164,    2, 0x08,   28 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN10GameScreenE.offsetsAndSizes,
    qt_meta_data_ZN10GameScreenE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10GameScreenE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameScreen, std::true_type>,
        // method 'gameEnded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'returnToLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetPotionPurchased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'freezePotionPurchased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'superPotionPurchased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'startCountdown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pauseGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'endGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_shopButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exitButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onGemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_resetButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetBoard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'redealToGrid'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_gameOverDialogAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_gameOverDialogRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_resetPotionPurchased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_freezePotionPurchased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_superPotionPurchased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void GameScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<GameScreen *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->gameEnded((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->returnToLogin(); break;
        case 2: _t->resetPotionPurchased((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->freezePotionPurchased((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->superPotionPurchased((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->startCountdown(); break;
        case 6: _t->pauseGame(); break;
        case 7: _t->endGame((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_shopButton_clicked(); break;
        case 9: _t->on_exitButton_clicked(); break;
        case 10: _t->onGemClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 11: _t->on_resetButton_clicked(); break;
        case 12: _t->resetBoard(); break;
        case 13: _t->redealToGrid(); break;
        case 14: _t->on_gameOverDialogAccepted(); break;
        case 15: _t->on_gameOverDialogRejected(); break;
        case 16: _t->on_resetPotionPurchased((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_freezePotionPurchased((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_superPotionPurchased((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (GameScreen::*)(int );
            if (_q_method_type _q_method = &GameScreen::gameEnded; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (GameScreen::*)();
            if (_q_method_type _q_method = &GameScreen::returnToLogin; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (GameScreen::*)(int );
            if (_q_method_type _q_method = &GameScreen::resetPotionPurchased; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (GameScreen::*)(int );
            if (_q_method_type _q_method = &GameScreen::freezePotionPurchased; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (GameScreen::*)(int );
            if (_q_method_type _q_method = &GameScreen::superPotionPurchased; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *GameScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10GameScreenE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void GameScreen::gameEnded(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameScreen::returnToLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameScreen::resetPotionPurchased(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameScreen::freezePotionPurchased(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GameScreen::superPotionPurchased(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
