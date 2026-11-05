// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall func_004a5450();
extern "C" void __stdcall func_004d97c0();
extern "C" void __stdcall func_0040c470();
extern "C" void __stdcall func_009160c0();
extern "C" void __stdcall func_00720d50();

struct RefCounted {
    void* vptr;
    long refcount;
    long weakref;
};

struct SelectionLasso {
    char pad0[0x98];
    char field_98[0x1c];
    char field_b4[0x10];
    void func(int);
};

void SelectionLasso::func(int arg)
{
    RefCounted* p;
    char local[0x10];
    bool changed;

    func_004a5450();
    p = *(RefCounted**)local;
    changed = (p != (RefCounted*)arg);
    if (p) {
        if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
            p->vptr;
            ((void (__thiscall*)(RefCounted*))((void**)p->vptr)[1])(p);
            if (_InterlockedExchangeAdd(&p->weakref, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)p->vptr)[2])(p);
            }
        }
    }
    if (changed) {
        func_004d97c0();
        func_00720d50();
        if (p) {
            if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)p->vptr)[1])(p);
                if (_InterlockedExchangeAdd(&p->weakref, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))((void**)p->vptr)[2])(p);
                }
            }
        }
        func_0040c470();
        func_009160c0();
    }
}
