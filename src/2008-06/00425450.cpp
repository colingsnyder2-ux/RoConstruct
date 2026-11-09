// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_treeinvoke_3f4051b61ff3cd23.cpp

// Candidate translation unit (score above; library headers required).
#include <intrin.h>

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Handle;

struct Lock {
    void* handle;
    bool criticalSection;
    unsigned int count;
    void lock();
    void unlock();
};

struct Guard {
    Lock* mutex;
    bool owned;
    Guard(Lock* p);
    ~Guard();
};

struct Iterator {
    void* values[3];
};

struct Tree {
    void lookup(Iterator* result, Handle* value);
};

struct Owner {
    void** vtable;
    char padding[0xc0];
    Lock mutex;
};

struct Node {
    char padding[0x50];
    unsigned char flags;
    char padding2[3];
    Owner* owner;
    unsigned int reserved;
    Tree tree;
    void invoke(int unused, Handle value);
};

__forceinline Guard::Guard(Lock* p)
    : mutex(p), owned(false)
{
    mutex->lock();
    owned = true;
}

__forceinline Guard::~Guard()
{
    if (owned)
        mutex->unlock();
}

void Node::invoke(int unused, Handle value)
{
    if (flags & 2) {
        Guard guard(&owner->mutex);
        _ReadWriteBarrier();
        Iterator result;
        tree.lookup(&result, &value);
    }

    typedef void (__thiscall *Notify)(Owner*, void*);
    ((Notify)owner->vtable[87])(owner, (char*)this - 4);
}