// from server: 29% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall func_006bc8b0();
extern "C" void __stdcall func_007e7910();

struct Sub1 {
    void* vptr;
    long ref1;
    long ref2;
};

struct Sub2 {
    void* vptr;
    long ref1;
    long ref2;
};

struct Outer {
    char pad0[0x1d0];
    int field_1d0;
    Sub1 sub_1d4;
    Sub2 sub_1d8;
    char field_1dc;
    int field_1e0;
};

struct Arg {
    char pad0[0x108];
};

struct S {
    void* vptr;
    char pad[0x1d0 - 4];
    int field_1d0;
    Sub1 sub_1d4;
    Sub2 sub_1d8;
    char field_1dc;
    int field_1e0;
    void ctor(Arg* a, void* b, void* c);
};

void S::ctor(Arg* a, void* b, void* c)
{
    void* p = a ? (void*)((char*)a + 0x108) : 0;
    void* q = b;
    if (q) {
        _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
    }
    func_006bc8b0();
    int saved = this->field_1d0;
    this->vptr = (void*)0x9a6aa8;
    this->field_1d0 = saved;
    func_007e7910();
    func_007e7910();
    this->field_1dc = 1;
    this->field_1e0 = 2;
    if (c) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)c + 4), -1) == 1) {
            void** vt = *(void***)c;
            ((void(__thiscall*)(void*))vt[1])(c);
            if (_InterlockedExchangeAdd((volatile long*)((char*)c + 8), -1) == 1) {
                void** vt2 = *(void***)c;
                ((void(__thiscall*)(void*))vt2[2])(c);
            }
        }
    }
}
