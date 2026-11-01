// from server: 56% by atomic.potato
struct Inner1 {
    char pad0[0x10];
    int f10;
    int f14;
    int f18;
    int f1c;
};

struct Inner2 {
    int f0;
    char pad4[0xc];
    int f10;
    int f14;
    int f18;
    int f1c;
};

struct S {
    char pad0[0x24];
    int f24;
    char pad28[0xc];
    int f34;
    int f38;
    char pad3c[0x44];
    int f80;
    char pad84[0x28];
    int fac;
    char fb0;
    char fb1;
    char fb2;
    char fb3;
    char fb4;
    char padb5[3];
    Inner1 inner_b8;
    int fbc;
    int fc0;
    int fc4;
    Inner2 inner_c8;
    int fe8;
    int fec;
    int ff0;
    int ff4;
    int ff8;
    int ffc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int f130;
    int f13c;
    void ctor();
};

extern "C" void __stdcall sub_00465f30();
extern "C" void __stdcall sub_0042c390(int, int);
extern "C" void* __cdecl sub_0080a05e(int);
extern "C" int __cdecl sub_00422680();
extern "C" void __stdcall sub_00465fc0(int, int, int);
extern "C" void __stdcall sub_00a41de8();

void S::ctor()
{
    this->fac = 0;
    this->f24 = 0;
    this->f34 = 0xa6f14c;
    this->f38 = 0;
    sub_00465f30();
    this->fb0 = 0;
    this->fb1 = 0;
    this->fb2 = 0;
    this->fb3 = 0;
    this->fb4 = 0;
    sub_0042c390(1, 0);
    this->fbc = 0;
    this->fc0 = 0;
    this->fc4 = 0;
    void* p = sub_0080a05e(4);
    if (p != 0) {
        *(int*)p = (int)&this->inner_c8;
    } else {
        p = 0;
    }
    this->inner_c8.f0 = (int)p;
    this->inner_c8.f10 = 0;
    this->inner_c8.f14 = 0;
    this->inner_c8.f18 = 0;
    this->inner_c8.f1c = 0;
    this->fe8 = 0;
    this->fec = 0;
    this->ff0 = 0;
    this->ff4 = 0;
    this->ff8 = 0;
    this->ffc = 0;
    this->f100 = 0;
    this->f104 = 0;
    this->f108 = 0;
    this->f10c = 0;
    this->f110 = 1;
    this->f114 = 0;
    this->f118 = 0;
    this->f11c = 0;
    this->f120 = 0;
    this->f124 = 0;
    this->f128 = 0;
    this->f12c = 0;
    this->f130 = 0;
    this->f13c = sub_00422680();
    this->f80 |= 0x40;
    sub_00465fc0((int)this, 0, 0x46c4d0);
    sub_00a41de8();
}
