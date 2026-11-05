// from server: 36% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner;

struct InnerVtbl {
    void* pad[1];
    void (__stdcall *fn1)(int);
    void (__stdcall *fn2)(int);
};

struct Inner {
    InnerVtbl* vtbl;
    volatile long ref1;
    volatile long ref2;
};

struct Mid {
    char pad[0x20];
    Inner* inner;
};

struct CRbxDocTemplate {
    char pad[0x54];
    int field54;
    char pad2[0x4];
    Mid* mid;
    void f(int, int);
};

struct String {
    char pad[0x10];
    const char* c_str();
};

extern "C" void __stdcall sub_402a60(void*, void*);
extern "C" void __stdcall sub_63079c(int, int, int);
extern "C" void* __stdcall sub_77e6a8(void*);

void CRbxDocTemplate::f(int a, int b)
{
    Inner* in;
    InnerVtbl* vt;
    void* p;
    String* s;
    int old;

    this->field54 = a;
    sub_402a60(&this->pad[0x58], &s);
    p = sub_77e6a8((char*)a + 0xc8);
    vt = this->mid->inner->vtbl;
    ((void (__stdcall*)(void*))vt->pad[0x58/4])(p);
    sub_63079c(0, 1, 0);
    in = this->mid->inner;
    if (in != 0) {
        old = _InterlockedExchangeAdd(&in->ref1, -1);
        if (old == 1) {
            ((void (__stdcall*)(int))in->vtbl->fn1)(0);
            old = _InterlockedExchangeAdd(&in->ref2, -1);
            if (old == 1) {
                ((void (__stdcall*)(int))in->vtbl->fn2)(0);
            }
        }
    }
}
