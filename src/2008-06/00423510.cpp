// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_selectioncount_27ab5239b9e30f66.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>
typedef boost::detail::shared_count Reference;

struct Shared {
    void* object;
    Reference reference;
    Shared();
    Shared(const Shared&);
};

inline Shared::Shared() : object(0) {}

inline Shared::Shared(const Shared& other) : object(other.object), reference(other.reference) {}

struct Record {
    unsigned char padding[12];
    void* object;
    Reference reference;
};

struct Selection {
    void select(void*);
};

struct BaseTable;

struct Base {
    BaseTable* table;
    Record* lookup(void*);
};

struct BaseTable {
    unsigned char padding[0x150];
    Selection* (__thiscall* selection)(Base*);
    Shared (Base::*shared)();
};

struct Transaction {
    unsigned char storage[12];
    Transaction(Shared);
    ~Transaction();
};

struct FlagGuard {
    unsigned char* flag;
    unsigned char previous;
    FlagGuard(unsigned char*);
    ~FlagGuard();
};

inline FlagGuard::FlagGuard(unsigned char* value)
    : flag(value), previous(*value) {
    *flag = 1;
}

inline FlagGuard::~FlagGuard() {
    *flag = previous;
}

struct CSelectionTreeCtrl {
    unsigned char padding[0x8d];
    unsigned char updating;
    unsigned char selecting;
    void forward(int, void*);
    void f(int, void*);
};

void CSelectionTreeCtrl::f(int mode, void* item) {
    if (mode == 0) {
        Base* base = reinterpret_cast<Base*>(
            reinterpret_cast<unsigned char*>(this) - 0x54);
        Record* record = base->lookup(item);
        Shared selected;
        if (record) {
            selected.object = record->object;
            selected.reference = record->reference;
        }
        {
            Transaction transaction((base->*(base->table->shared))());
            Selection* selection = base->table->selection(base);
            {
                void* objectCopy = selected.object;
                FlagGuard guard(&selecting);
                selection->select(objectCopy);
            }
        }
        {
            FlagGuard guard(&updating);
            forward(0, item);
        }
    } else {
        forward(mode, item);
    }
}