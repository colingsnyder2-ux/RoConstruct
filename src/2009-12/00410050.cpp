// from server: 55% by atomic.potato
struct Inner {
    int pad0;
    int pad4;
    int pad8;
    int padC;
    int pad10;
};

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct S {
    Base* f0;
    int f4;
    int f8;
    Base* fC;
    Base* f10;
    int f14;
    int f18;
    int f1C;
    Base* f20;
    void ctor(Inner* p);
};

extern "C" void __stdcall sub_40FB60(S* self, Inner* p);

void S::ctor(Inner* p) {
    sub_40FB60(this, p);
    this->f20 = (Base*)0x99fd90;
    this->f0 = (Base*)0x9a1be0;
    this->fC = (Base*)0x9a1bd8;
    this->f20 = (Base*)0x9a1bc8;
    Inner* ebx;
    if (p != 0) {
        ebx = (Inner*)((char*)p + 0xc);
    } else {
        ebx = 0;
    }
    Base* ecx = this->f10;
    Base* edi = *(Base**)((char*)ebx + 4);
    if (ecx != 0) {
        void (__thiscall *fn)(Base*) = *(void (__thiscall **)(Base*))(*(int*)ecx + 0x10);
        fn(ecx);
    }
    this->f10 = edi;
    if (edi != 0) {
        void (__thiscall *fn)(Base*) = *(void (__thiscall **)(Base*))(*(int*)edi + 0xc);
        fn(edi);
    }
    this->f14 = *(int*)((char*)ebx + 8);
    this->f18 = *(int*)((char*)ebx + 0xc);
    this->f1C = *(int*)((char*)ebx + 0x10);
}
