// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_446e753c9826d592.cpp

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
    unsigned char padding[20];
    void* object;
    Reference reference;
};

struct Selection {
    void select(void*);
};

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual Selection* selection();
    virtual Shared shared();
    Record* lookup(void*);
};

struct Transaction {
    void* storage;
    Transaction(Shared, bool);
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
    unsigned char padding[0x95];
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
            Transaction transaction(base->shared(), true);
            Selection* selection = base->selection();
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