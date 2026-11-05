// from server: 27% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);

struct Inner {
    char pad[8];
};

struct Sub {
    char pad0[4];
    Inner* p4;
    char pad8[4];
    void clear();
};

struct Obj {
    char pad0[0x1b0];
    void* p1b0;
    char pad1b4[0x1c];
    char f1d0;
    char pad1d1[0x1f];
    void* f1f0;
    char pad1f4[0x1c];
    Sub sub;
    char pad2d0[0x100];
    void method1();
    void method2();
    void method3();
};

struct Arg {
    void* p0;
    void* p4;
};

extern "C" void __cdecl func_441df0(void*, Arg*);
extern "C" void __cdecl func_43b1e0(void*, Arg*);
extern "C" void __cdecl func_725750(void*);
extern "C" void __cdecl func_725770(void*);
extern "C" void __cdecl func_5b32e0(void*, void*);
extern "C" void __cdecl func_41da00(void*);

void Obj::method1()
{
    char* base = (char*)this;
    Obj* self = (Obj*)(base + 0x1d0);
    void* a1 = *(void**)(base + 0x30);
    void* a2 = *(void**)(base + 0x34);
    void* a3 = *(void**)(base + 0x38);
    void* a4 = *(void**)(base + 0x3c);
    void* a5 = *(void**)(base + 0x40);

    if (a1) {
        Arg arg;
        arg.p0 = a1;
        arg.p4 = a2;
        if (a2) {
            _InterlockedExchangeAdd((volatile long*)((char*)a2 + 4), 1);
        }
        func_441df0((char*)self - 0x1d0, &arg);
    }
    if (a3) {
        Arg arg;
        arg.p0 = a3;
        arg.p4 = a4;
        if (a4) {
            _InterlockedExchangeAdd((volatile long*)((char*)a4 + 4), 1);
        }
        func_43b1e0((char*)self - 0x1d0, &arg);
    }

    char* p = base - 0x50;
    func_725750(p);
    *(char*)(base - 0x1b) = 1;

    void* q = *(void**)(base - 0x14);
    void* r = *(void**)((char*)q + 4);
    char* s = base - 0x18;
    func_5b32e0(s, r);

    void* t = *(void**)(s + 4);
    *(void**)((char*)t + 4) = t;
    void* u = *(void**)(s + 4);
    *(void**)(s + 8) = 0;
    *(void**)u = u;
    void* v = *(void**)(s + 4);
    *(void**)((char*)v + 8) = v;

    func_725750(base - 0x50);

    if (*(char*)(base - 0x1c) == 0) {
        void* w = *(void**)(base - 0x1b0);
        if (w) {
            PostMessageA(w, 0, 0, 0x465);
        }
        *(char*)(base - 0x1c) = 1;
    }

    func_725770(base - 0x50);
    func_725770(base - 0x50);
    func_41da00(base + 0x30);
}
