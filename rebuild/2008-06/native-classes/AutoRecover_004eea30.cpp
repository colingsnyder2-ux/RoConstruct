// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: best-effort reconstruction, not compiled or diffed. Locals, lock guard and temp type are guesses from the disassembly.
#include <windows.h>

namespace boost { void call_once(void (*f)(), long& flag); }

extern "C" {
int __fastcall fn_004e9550(void* self, int unusedEdx, int a1, int a2);
int __fastcall fn_004d7e30(void* self, int unusedEdx);
int __fastcall fn_004e5cd0(void* self, int unusedEdx, int a1);
int __fastcall fn_004e7630(void* self, int unusedEdx, int a1, int a2);
int __fastcall fn_004e5d30(void* self, int unusedEdx, int a1);
int fn_006a0920(int a1);
int __fastcall fn_004fcfb0(void* self, int unusedEdx, int a1, int a2);
int fn_004ece90(void);
void __fastcall fn_00563090(void* self, int unusedEdx);
void __fastcall fn_005630e0(void* self, int unusedEdx);
void fn_004d97b0(void);
void* fn_00508580(unsigned size, unsigned align);
void fn_00508a30(void* p, unsigned char v, unsigned n);
extern long g_00972740;
}

struct Local_004eea30_Node {
    unsigned key;
    unsigned key2;
    int value[4];
    Local_004eea30_Node* next;
};

struct Local_004eea30_Registry {
    int pad0[2];
    Local_004eea30_Node** buckets;
    unsigned bucketCount;
    char mutex[0x4c];
    int insertCount;
};

extern Local_004eea30_Registry* g_00972728;

struct Local_004eea30_Lock {
    void* m;
    explicit Local_004eea30_Lock(void* mm) : m(mm) { fn_00563090(m, 0); }
    ~Local_004eea30_Lock() { fn_005630e0(m, 0); }
};

static Local_004eea30_Node* Local_004eea30_find(Local_004eea30_Registry* r, unsigned k)
{
    Local_004eea30_Node* n = r->buckets[k % r->bucketCount];
    while (n) {
        if (n->key == k && n->key2 == k)
            break;
        n = n->next;
    }
    return n;
}

extern "C" int fn_004eea30(unsigned guid)
{
    boost::call_once(fn_004d97b0, g_00972740);
    Local_004eea30_Registry* r = g_00972728;
    Local_004eea30_Lock lock(r->mutex);

    int result = 0;
    if (!Local_004eea30_find(r, guid)) {
        struct Tmp { int vt; int size; int data; } tmp;
        tmp.size = 10;
        tmp.data = (int)fn_00508580(0x28, 0x10);
        fn_00508a30((void*)tmp.data, 0, 0x28);
        fn_004e9550(r, 0, (int)&guid, (int)&tmp);
        fn_004d7e30(&tmp, 0);
    }
    Local_004eea30_Node* n = Local_004eea30_find(r, guid);
    if (!fn_004e5cd0(&n->value, 0, guid)) {
        fn_004e7630(&n->value, 0, guid, 0);
    }
    int* slot = (int*)fn_004e5d30(&n->value, 0, guid);
    result = *slot;
    if (!result) {
        int obj = fn_006a0920(0x8c);
        if (obj)
            obj = fn_004fcfb0((void*)obj, 0, guid, guid);
        result = obj;
        *slot = obj;
        if (++r->insertCount % 100 == 0)
            fn_004ece90();
    }
    return result;
}
