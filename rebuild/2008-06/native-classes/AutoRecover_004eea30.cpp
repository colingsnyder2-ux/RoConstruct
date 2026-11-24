// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: argument roles, the registry layout and the node layout are guesses from the disassembly only.
#include <windows.h>

namespace boost { void call_once(void (*f)(), long& flag); }
namespace RBX {
class GuidRegistryMutex {
public:
    void lock();
    void unlock();
};
}
namespace G3D {
namespace System {
void* alignedMalloc(size_t bytes, size_t alignment);
void memset(void* dst, unsigned char v, size_t n);
}
class ReferenceCountedObject {
public:
    void ReferenceCountedObject_zeroWeakPointers();
};
}

extern "C" void fn_004d97b0();
extern "C" long g_00972740;
extern "C" char* g_00972728;
// INFERRED: vtable of the temporary container object (was hardcoded 0x826bfc)
extern "C" char g_00826bfc[];
extern "C" int __fastcall fn_004e9550(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e5cd0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004e7630(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004e5d30(void* self, int unusedEdx, int a1);
extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_004fcfb0(void* self, int unusedEdx, int a1, int a2);
extern "C" int fn_004ece90(void);
extern "C" void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p);

struct RegNode {
    unsigned key0;
    unsigned key1;
    int payload[4];
    RegNode* next;
};

// INFERRED: temporary container constructed when no node exists for the key
struct TmpObj {
    void* vtbl;
    int size;
    void* data;
    int pad;
};

static RegNode* findNode(char* reg, unsigned key)
{
    unsigned buckets = *(unsigned*)(reg + 0xc);
    RegNode** table = *(RegNode***)(reg + 8);
    RegNode* n = table[key % buckets];
    while (n) {
        if (n->key0 == key && n->key1 == key)
            return n;
        n = n->next;
    }
    return 0;
}

extern "C" int* fn_004eea30(int arg1, unsigned arg2)
{
    boost::call_once(fn_004d97b0, g_00972740);
    char* reg = g_00972728;
    RBX::GuidRegistryMutex* mtx = (RBX::GuidRegistryMutex*)(reg + 0x10);
    mtx->lock();

    int* result = 0;
    RegNode* node = findNode(reg, arg2);
    if (!node) {
        TmpObj tmp;
        tmp.vtbl = (void*)g_00826bfc;
        tmp.size = 10;
        tmp.pad = 0;
        tmp.data = G3D::System::alignedMalloc(0x28, 0x10);
        G3D::System::memset(tmp.data, 0, 0x28);
        int keyCopy[2];
        keyCopy[0] = (int)arg2;
        fn_004e9550(reg, 0, (int)keyCopy, (int)&tmp);
        tmp.vtbl = (void*)g_00826bfc;
        fn_004d7e30(&tmp, 0);
    }
    node = findNode(reg, arg2);
    void* entry = (char*)node + 8;

    if (!(char)fn_004e5cd0(entry, 0, arg1)) {
        int tmp2[4];
        // INFERRED: array constructed/destructed around the insert call
        fn_004e7630(entry, 0, arg1, (int)tmp2);
    }
    int* slot = (int*)fn_004e5d30(entry, 0, arg1);
    result = (int*)*slot;
    if (!result) {
        void* mem = (void*)fn_006a0920(0x8c);
        void* obj = 0;
        if (mem)
            obj = (void*)fn_004fcfb0(mem, 0, arg1, (int)arg2);
        result = (int*)obj;
        fn_00598fa0(slot, 0, obj);
        int cnt = ++*(int*)(reg + 0x5c);
        if (cnt % 100 == 0) {
            G3D::ReferenceCountedObject* p = (G3D::ReferenceCountedObject*)*slot;
            if (p)
                InterlockedIncrement((LONG*)((char*)p + 4));
            fn_004ece90();
            if (p) {
                if (InterlockedDecrement((LONG*)((char*)p + 4)) == 0) {
                    p->ReferenceCountedObject_zeroWeakPointers();
                    typedef void (__thiscall *DtorFn)(void*, int);
                    void** vt = *(void***)p;
                    ((DtorFn)vt[0])(p, 1);
                }
            }
        }
    }
    mtx->unlock();
    return result;
}
