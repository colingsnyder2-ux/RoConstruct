// from server: 44% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);
extern "C" int __stdcall compare_helper(const char*, const char*);

struct Vtbl {
    void* pad0;
    void* fn4;
    void* fn8;
};

struct Obj {
    Vtbl* vt;
    int refcount;
    int refcount2;
};

struct Inner {
    char pad[0x100];
    void sub_423240(void*);
};

struct CRobloxView {
    char pad[0x58];
    void* field_58;
    char pad2[0x20];
    void* field_78;
    char pad3[0x10];
    void* field_88;
    char pad4[0x78];
    Inner* field_100;
    void func(void* a, void* b, void* c);
};

void CRobloxView::func(void* a, void* b, void* c) {
    Obj* esi = (Obj*)a;
    Vtbl* vt = esi->vt;
    void* r = ((void* (__thiscall*)(Obj*))vt->fn4)(esi);
    if (compare_helper((const char*)r + 4, (const char*)0x786ddc) != 0) {
        Vtbl* vt2 = esi->vt;
        void* r2 = ((void* (__thiscall*)(Obj*))vt2->fn4)(esi);
        if (compare_helper((const char*)r2 + 4, (const char*)0x792ba4) == 0) {
            PostMessageA(*(void**)((char*)this - 0x58), 0, 0, 0x46b);
        }
    }
    Vtbl* vt3 = esi->vt;
    void* r3 = ((void* (__thiscall*)(Obj*))vt3->fn4)(esi);
    if (compare_helper((const char*)r3 + 4, (const char*)0x792ba4) == 0) {
        void* p;
        if ((char*)this - 0x78 != 0) {
            p = (char*)this + 8;
        } else {
            p = 0;
        }
        ((Inner*)((char*)esi + 0x100))->sub_423240(p);
    }
    if (esi != 0) {
        if (_InterlockedExchangeAdd((volatile long*)&esi->refcount, -1) == 1) {
            Vtbl* vt4 = esi->vt;
            ((void (__thiscall*)(Obj*))vt4->fn4)(esi);
            if (_InterlockedExchangeAdd((volatile long*)&esi->refcount2, -1) == 1) {
                Vtbl* vt5 = esi->vt;
                ((void (__thiscall*)(Obj*))vt5->fn8)(esi);
            }
        }
    }
}
