// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_stockvolatilecontrol_01622ab042b10c59.cpp

// Candidate translation unit (score above; library headers required).


#include <boost/shared_ptr.hpp>

struct String {
    char storage[28];
    __declspec(dllimport) String(const String&);
};

typedef void (__thiscall *StringCopy)(String*, const String&);
extern StringCopy copy_string;

struct Control { long reserved; volatile long references; };

struct Value {
    String name;
    volatile unsigned long data;
    void* volatile object;
    Control* volatile control;

    Value(const Value&);
    ~Value();
};

struct Node {
    char links[12];
    Value value;
};

struct Tree {
    char padding[24];
    Node* sentinel;
};

struct Owner {
    Tree* tree;
};

struct Iterator {
    Owner* owner;
    Node* node;

    Iterator& operator++();
};

typedef void (__cdecl *Callback)(const Value&);

inline Value::Value(const Value& other)
 : name(other.name) {
    data = other.data;
    object = other.object;
    Control* p = other.control;
    control = p;
    if (p) _InterlockedIncrement(&p->references);
}

Callback __cdecl process(Iterator first, Iterator last, Callback callback)
{
    Iterator current = first;
    Iterator finish = last;
    Owner* owner = current.owner;
    Node* node = current.node;

    for (;;) {
        if (!owner || owner != finish.owner)
            _invalid_parameter_noinfo();

        if (node == finish.node)
            break;

        if (!owner)
            _invalid_parameter_noinfo();
        Tree* tree = owner ? owner->tree : reinterpret_cast<Tree*>(owner);

        if (node == tree->sentinel)
            _invalid_parameter_noinfo();

        {
            Value value(node->value);
            callback(value);
        }

        ++current;
        node = current.node;
        owner = current.owner;
    }

    return callback;
}