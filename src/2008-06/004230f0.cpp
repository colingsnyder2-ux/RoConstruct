// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_treevirtual_09a06d43df0bafe5.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Owner;
struct Pair : Owner {};
struct Lock {
    unsigned char storage[12];

    Lock(Owner value);
    ~Lock();
};

struct FlagGuard {
    unsigned char* address;
    unsigned char previous;

    FlagGuard(unsigned char& flag);
    ~FlagGuard();
};

inline FlagGuard::FlagGuard(unsigned char& flag)
    : address(&flag), previous(flag)
{
    flag = 1;
}

inline FlagGuard::~FlagGuard()
{
    *address = previous;
}

struct Selection {
    void select(void* object);
    void deselect(void* object);
};

struct Item {
    unsigned char padding[12];
    Pair value;
};

struct Notification {
    unsigned char padding0[4];
    int valid;
    unsigned char padding1[28];
    Item* item;
};

struct Tree {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual Selection* selection();
    virtual Pair context();
    unsigned char padding[222];
    unsigned char changing;

    void f(Notification* notification, unsigned char select);
};

void Tree::f(Notification* notification, unsigned char select)
{
    if (notification->valid && notification->item) {
        Owner object(notification->item->value);
        if (object.get()) {
            Lock lock(context());
            Selection* selection = this->selection();
            FlagGuard guard(changing);
            if (select)
                selection->select(object.get());
            else
                selection->deselect(object.get());
        }
    }
}
