// from server: 70% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad[0x28];
    int field28;
};

struct Obj {
    void* vptr;
    volatile long ref4;
    volatile long ref8;
};

struct Sel {
    char pad[0x28];
    Inner inner;
    char f();
    char g();
};

extern int* __stdcall sub_73f730(Inner* self, int* out);

char Sel::f()
{
    int local;
    int* p = sub_73f730(&inner, &local);
    bool empty = (*p == 0);
    Obj* o = (Obj*)local;
    if (o) {
        if (_InterlockedExchangeAdd(&o->ref4, -1) == 1) {
            void** vt = (void**)o->vptr;
            ((void (__thiscall*)(Obj*))vt[1])(o);
        }
        if (_InterlockedExchangeAdd(&o->ref8, -1) == 1) {
            void** vt = (void**)o->vptr;
            ((void (__thiscall*)(Obj*))vt[2])(o);
        }
    }
    if (empty)
        return 0;
    return g();
}
