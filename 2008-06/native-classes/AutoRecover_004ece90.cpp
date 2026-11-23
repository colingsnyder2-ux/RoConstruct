// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were available, so every type below is reconstructed from the
// disassembly's field offsets. It is a best-effort reconstruction, not a verified match.
#include <windows.h>

namespace RBX {
    // INFERRED: mutex embedded at registry+0x10, lock()/unlock() are thiscall members
    class GuidRegistryMutex {
    public:
        void lock();
        void unlock();
    };
}

namespace boost {
    void call_once(void (*f)(), long& flag);
}

extern "C" void fn_004d97b0();
extern "C" long g_data_00972740;

extern "C" int __fastcall fn_004e6cf0(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004e6c90(void* self, int unusedEdx, int a1, int a2);
extern "C" void __fastcall fn_004d7240(void* self, int unusedEdx);
extern "C" void __fastcall fn_00438770(void* self, int unusedEdx);

// INFERRED: intrusive ref-counted state block (refcount at +4, node list at +8)
struct StateNode {
    struct Obj { void** vtbl; }* obj;   // object destroyed through vtable slot 1
    StateNode* next;
};
struct StateBlock {
    void** vtbl;                        // slot 0 = deleting destructor
    volatile LONG refs;
    StateNode* list;
};

struct HashNode {
    char pad0[8];
    int  innerPad;                      // +8 (container id of the inner hash)
    char pad1[4];
    HashNode** innerBuckets;            // +0x10
    int  innerSize;                     // +0x14
};

struct HashIter {
    int idx;
    void* cur;
    void* owner;
    int size;
    void** buckets;
    bool atEnd;
};

struct Registry {
    char pad0[8];
    void** buckets;                     // +8
    int size;                           // +0xc
    RBX::GuidRegistryMutex mutex;       // +0x10
    char pad1[0x1c - 0x11];
    void* proxy1;                       // +0x1c
    char pad2[0x34 - 0x20];
    void** head1;                       // +0x34
    char pad3[0x3c - 0x38];
    void* proxy2;                       // +0x3c
    char pad4[0x54 - 0x40];
    void** head2;                       // +0x54
};

struct TreeIter {
    void* proxy;
    void* node;
};

static void releaseState(StateBlock** slot)
{
    StateBlock* p = *slot;
    if (p) {
        if (InterlockedDecrement(&p->refs) == 0) {
            StateNode* n = p->list;
            while (n) {
                // call virtual slot 1 of the held object
                typedef void (__fastcall *Fn)(void*, int);
                ((Fn)n->obj->vtbl[1])(n->obj, 0);
                StateNode* cur = n;
                n = n->next;
                operator delete(cur);
            }
            if (p) {
                typedef void (__fastcall *Dtor)(void*, int, int);
                ((Dtor)p->vtbl[0])(p, 0, 1);
            }
        }
        *slot = 0;
    }
}

static void beginIter(HashIter& it, void* owner, int size, void** buckets)
{
    it.owner = owner;
    it.size = size;
    it.buckets = buckets;
    it.idx = 0;
    it.cur = 0;
    it.atEnd = false;
    if (size == 0) {
        it.atEnd = true;
        return;
    }
    it.cur = buckets[0];
    if (!it.cur) {
        int i = 0;
        for (;;) {
            ++i;
            if (i >= size) {
                it.idx = i;
                it.atEnd = true;
                break;
            }
            if (buckets[i]) {
                it.cur = buckets[i];
                it.idx = i;
                break;
            }
        }
    }
}

namespace {
struct ScopedLock {
    RBX::GuidRegistryMutex* m;
    bool locked;
    explicit ScopedLock(RBX::GuidRegistryMutex* mm) : m(mm), locked(false) { m->lock(); locked = true; }
    ~ScopedLock() { if (locked) m->unlock(); }
};
}

extern "C" void fn_004ece90()
{
    boost::call_once(fn_004d97b0, g_data_00972740);

    extern Registry* g_data_00972728;
    Registry* reg = g_data_00972728;

    ScopedLock lock(&reg->mutex);

    HashIter outer;
    beginIter(outer, reg, reg->size, reg->buckets);

    while (!outer.atEnd) {
        HashNode* node = (HashNode*)outer.cur;
        HashIter inner;
        beginIter(inner, (char*)node + 8, node->innerSize, (void**)node->innerBuckets);

        while (!inner.atEnd) {
            char* e = (char*)inner.cur;
            StateBlock** slot = (StateBlock**)(e + 0x10);
            if (*slot && (*slot)->refs == 1) {
                releaseState(slot);
            }
            char tmp[16];
            fn_004e6cf0(&inner, 0, (int)tmp, 0);
        }
        char tmp2[16];
        fn_004e6c90(&outer, 0, (int)tmp2, 0);
    }

    // first tree: value pointer at node+0x1c
    {
        TreeIter it;
        it.proxy = reg->proxy1;
        it.node = *(void**)reg->head1;
        while (it.node != (void*)reg->head1) {
            StateBlock** slot = (StateBlock**)((char*)it.node + 0x1c);
            if (*slot && (*slot)->refs == 1) {
                releaseState(slot);
            }
            fn_004d7240(&it, 0);
        }
    }

    // second tree: value pointer at node+0x24
    {
        TreeIter it;
        it.proxy = reg->proxy2;
        it.node = *(void**)reg->head2;
        while (it.node != (void*)reg->head2) {
            StateBlock** slot = (StateBlock**)((char*)it.node + 0x24);
            if (*slot && (*slot)->refs == 1) {
                releaseState(slot);
            }
            fn_00438770(&it, 0);
        }
    }
}
