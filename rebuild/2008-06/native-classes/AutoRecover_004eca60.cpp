// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <map>

// INFERRED: the layouts below are reconstructed from the disassembly offsets only.
// This is a best-effort approximation; the real class names are unknown.

namespace RBX {
    class GuidRegistryMutex {
    public:
        void lock();
        void unlock();
    };
}

namespace boost {
    void call_once(void (*f)(), long& flag);
}

// INFERRED: callback list node, vtable at +0, next at +4
struct CbNode {
    virtual void slot0();
    virtual void destroyPayload();
    CbNode* next;
};

// INFERRED: counted block, vtable at +0, refcount at +4, callback list at +8
struct Counted {
    virtual void deletingDtor(int flags);
    volatile LONG refs;
    CbNode* list;
};

// INFERRED: hand-rolled hash container header: buckets at +8, count at +0xc
struct HashEntry {
    HashEntry* pad0;
    HashEntry* pad1;
    void* inner[1]; // placeholder (not used directly)
};

struct InnerEntry {
    char pad[0x10];
    Counted* value; // +0x10
};

struct InnerTable {
    int pad[2];
    InnerEntry** buckets; // +8
    int count;            // +0xc
};

struct OuterEntry {
    char pad[8];
    InnerTable inner; // +8
};

struct Key12 {
    int a, b, c;
    bool operator<(const Key12& o) const {
        if (a != o.a) return a < o.a;
        if (b != o.b) return b < o.b;
        return c < o.c;
    }
};

struct Key20 {
    int a, b, c, d, e;
    bool operator<(const Key20& o) const {
        if (a != o.a) return a < o.a;
        if (b != o.b) return b < o.b;
        if (c != o.c) return c < o.c;
        if (d != o.d) return d < o.d;
        return e < o.e;
    }
};

struct GuidRegistry {
    int pad0[2];
    OuterEntry** buckets;           // +8
    int bucketCount;                // +0xc
    RBX::GuidRegistryMutex mutex;   // +0x10
    std::map<Key12, Counted*> mapA;
    std::map<Key20, Counted*> mapB;
};

extern "C" GuidRegistry* g_guidRegistry_00972730;
extern "C" long g_onceFlag_00972748;
extern "C" void fn_004d9870();

static void releaseIfUnique(Counted*& p)
{
    if (p && p->refs == 1) {
        if (InterlockedDecrement(&p->refs) == 0) {
            CbNode* n = p->list;
            while (n) {
                n->destroyPayload();
                CbNode* cur = n;
                n = n->next;
                ::operator delete(cur);
            }
            if (p)
                p->deletingDtor(1);
        }
        p = 0;
    }
}

struct LockGuard {
    RBX::GuidRegistryMutex* m;
    explicit LockGuard(RBX::GuidRegistryMutex* mm) : m(mm) { m->lock(); }
    ~LockGuard() { m->unlock(); }
};

extern "C" void fn_004eca60()
{
    boost::call_once(fn_004d9870, g_onceFlag_00972748);
    GuidRegistry* reg = g_guidRegistry_00972730;

    LockGuard guard(&reg->mutex);

    for (int i = 0; i < reg->bucketCount; ++i) {
        OuterEntry* oe = reg->buckets[i];
        if (!oe)
            continue;
        InnerTable& t = oe->inner;
        for (int j = 0; j < t.count; ++j) {
            InnerEntry* ie = t.buckets[j];
            if (!ie)
                continue;
            releaseIfUnique(ie->value);
        }
    }

    for (std::map<Key12, Counted*>::iterator it = reg->mapA.begin(); it != reg->mapA.end(); ++it) {
        releaseIfUnique(it->second);
    }

    for (std::map<Key20, Counted*>::iterator it = reg->mapB.begin(); it != reg->mapB.end(); ++it) {
        releaseIfUnique(it->second);
    }
}
