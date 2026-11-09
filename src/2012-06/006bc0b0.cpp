// from server: 0% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_b22654();
extern "C" void __stdcall sub_b2263c();
extern "C" void __stdcall sub_6ba030();
extern "C" void __stdcall sub_7adc40();
extern "C" void __stdcall sub_40b750();

struct Str {
    char pad[0x10];
    Str();
    ~Str();
};

struct Ref {
    void (__stdcall *dtor)(void*);
    void (__stdcall *dtor2)(void*);
};

struct Obj {
    Ref* vt;
    volatile long ref1;
    volatile long ref2;
};

void f(char* a, void* b, Obj* c, void* d, void* e, void* g)
{
    Str s;
    sub_6ba030();
    sub_7adc40();
    sub_b2263c();
    sub_40b750();
    if (c) {
        if (_InterlockedExchangeAdd(&c->ref1, -1) == 1) {
            c->vt->dtor(c);
            if (_InterlockedExchangeAdd(&c->ref2, -1) == 1) {
                c->vt->dtor2(c);
            }
        }
    }
    if (g) {
        void* p = *(void**)g;
        if (p) {
            ((void (__stdcall*)(void*, void*, int))p)(e, d, 2);
        }
    }
}
