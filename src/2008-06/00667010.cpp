// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_seatedsignalresult_1c3176a15e90692d.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/last_value.hpp>
struct Human {
    char padding[20];
    char key;
};

struct Sink {
    boost::last_value<void>::result_type update(bool);
};

struct Node {
    char padding[16];
    Sink sink;
};

struct Lookup {
    Node* find(void*);
};

extern Lookup lookup;

struct Primary {
    virtual void primary();
};

struct Secondary {
    virtual void secondary();
};

struct Base : Primary, Secondary {
    Base(Human*);
    ~Base();
    void set(int);
};

struct Seated : Base {
    Seated(Human*);
    virtual void primary();
    virtual void secondary();
};

Seated::Seated(Human* const human) : Base(human)
{
    Node* node = lookup.find(human ? &human->key : 0);
    if (node)
    {
        node->sink.update(true);
    }
    set(1);
}
