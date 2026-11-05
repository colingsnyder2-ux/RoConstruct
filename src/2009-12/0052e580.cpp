// from server: 37% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct RefObj {
    VBase* vt;
    volatile long ref1;
    volatile long ref2;
};

struct Outer {
    char pad0[0x14];
    int field14;
    char pad18[0x18];
    char pad30[0x30];
    void dtor();
};

struct S {
    char pad0[4];
    char pad4[0x14];
    char pad18[4];
    char pad1c[4];
    void dtor();
};

void __stdcall sub_637b00();

void S::dtor() {
    RefObj* p = *(RefObj**)((char*)this - 4);
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1) {
            p->vt->f1();
        }
        if (_InterlockedExchangeAdd(&p->ref2, -1) == 1) {
            p->vt->f2();
        }
    }
    *(int*)((char*)this + 0x14) = -1;
    *(int*)((char*)this) = 0x9bcc34;
    *(int*)((char*)this + 4) = 0x9bcc28;
    *(int*)((char*)this + 0x18) = 0x9bcc1c;
    *(int*)((char*)this + 0x1c) = 0x9bcc14;
    sub_637b00();
}
