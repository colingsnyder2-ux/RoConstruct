// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: minimal local declarations, since no headers for these types were provided.
// The names and signatures are chosen so the MSVC mangled names match the call comments.

namespace boost {
    void call_once(void (*f)(), long& flag);
}

namespace RBX {
    class GuidRegistryMutex {
    public:
        void lock();
        void unlock();
    };
}

namespace G3D {
    class System {
    public:
        static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
        static void memset(void* dst, unsigned char value, unsigned int n);
    };

    class ReferenceCountedObject {
    public:
        virtual ~ReferenceCountedObject() {}
        volatile long refCount;
        void ReferenceCountedObject_zeroWeakPointers();
    };

    class Texture : public ReferenceCountedObject {
    };
}

extern "C" G3D::Texture* fn_004ef430(unsigned int a1, unsigned int a2);

namespace G3D {
    template <class T>
    class ReferenceCountedPointer {
        T* m_p;
        void setPointer(T* p);
        friend G3D::Texture* ::fn_004ef430(unsigned int, unsigned int);
    public:
        ReferenceCountedPointer() : m_p(0) {}
        T* get() const { return m_p; }
    };
}

extern "C" int __fastcall fn_004e9890(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e5cd0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004e7630(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004e5d30(void* self, int unusedEdx, int a1);
extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_00500180(void* self, int unusedEdx, int a1, int a2);
extern "C" int fn_004ed6f0(void);
extern "C" void fn_004d98d0(void);  // INFERRED: one-time init callback

// INFERRED: layout of the registry singleton
struct TexRegistry {
    int pad0;
    int pad4;
    void** buckets;          // +8
    unsigned int bucketCount; // +0xc
    RBX::GuidRegistryMutex mutex; // +0x10
    char pad[0x5c - 0x11];
    int counter;             // +0x5c
};

struct TexNode {
    unsigned int hash;   // +0
    unsigned int key;    // +4
    char value[0x10];    // +8 (inner table lives here)
    TexNode* next;       // +0x18
};

extern "C" long g_0097274c;          // once flag
extern "C" TexRegistry* g_00972734;  // registry singleton pointer
extern "C" char g_00826c14[];        // INFERRED: vtable of temporary inner table

// INFERRED: temporary inner table, 10 buckets
struct TmpTable {
    void* vtbl;
    int a;
    void* buckets;
    int n;
};

struct LockGuard {
    RBX::GuidRegistryMutex* m;
    explicit LockGuard(RBX::GuidRegistryMutex* mm) : m(mm) { m->lock(); }
    ~LockGuard() { m->unlock(); }
};

struct SlotTemp {
    void* p;
    SlotTemp() : p(0) {}
    ~SlotTemp() {}
};

static TexNode* findNode(TexRegistry* r, unsigned int key)
{
    TexNode* n = (TexNode*)r->buckets[key % r->bucketCount];
    while (n) {
        if (n->hash == key && n->key == key)
            break;
        n = n->next;
    }
    return n;
}

extern "C" G3D::Texture* fn_004ef430(unsigned int a1, unsigned int a2)
{
    boost::call_once(fn_004d98d0, g_0097274c);
    TexRegistry* reg = g_00972734;
    LockGuard guard(&reg->mutex);

    G3D::Texture* result = 0;

    if (!findNode(reg, a2)) {
        TmpTable tmp;
        tmp.vtbl = (void*)g_00826c14;
        tmp.n = 10;
        tmp.a = 0;
        tmp.buckets = G3D::System::alignedMalloc(0x28, 0x10);
        G3D::System::memset(tmp.buckets, 0, 0x28);
        fn_004e9890(reg, 0, (int)&a2, (int)&tmp);
        tmp.vtbl = (void*)g_00826c14;
        fn_004d7e30(&tmp, 0);
    }

    TexNode* node = findNode(reg, a2);
    void* table = node->value;

    if (!(fn_004e5cd0(table, 0, (int)a1) & 0xff)) {
        SlotTemp v;
        fn_004e7630(table, 0, (int)a1, (int)&v);
    }

    G3D::ReferenceCountedPointer<G3D::Texture>* slot =
        (G3D::ReferenceCountedPointer<G3D::Texture>*)fn_004e5d30(table, 0, (int)a1);

    result = slot->m_p;
    if (result == 0) {
        void* mem = (void*)fn_006a0920(0x8c);
        G3D::Texture* t = 0;
        if (mem) {
            fn_00500180(mem, 0, (int)a1, (int)a2);
            t = (G3D::Texture*)mem;
        }
        slot->setPointer(t);
        result = t;

        reg->counter++;
        if (reg->counter % 100 == 0) {
            G3D::Texture* held = slot->m_p;
            if (held)
                InterlockedIncrement(&held->refCount);
            fn_004ed6f0();
            if (held) {
                if (InterlockedDecrement(&held->refCount) == 0) {
                    held->ReferenceCountedObject_zeroWeakPointers();
                    delete held;
                }
            }
        }
    }
    return result;
}
