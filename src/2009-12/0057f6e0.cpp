// from server: 32% by atomic.potato
struct Inner {
    void* p0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
};

struct Mid {
    char pad0[4];
    Inner inner;
    char pad18[0x24 - 0x18];
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    float f44;
};

struct Outer {
    char f0;
    char f1;
    char f2;
    char f3;
    char f4;
    char pad5[3];
    Mid mid;
};

extern "C" int* __stdcall sub_7f3860(int);
extern "C" void __fastcall sub_57d600(void*, int, int);
extern "C" void __fastcall sub_57e610(void*, int, int, int);

void __fastcall sub_57f6e0(Outer* self, int, int a2, int a3)
{
    self->f4 = *(char*)a2;
    sub_57d600(&self->mid, a3, 0);
    int* p = sub_7f3860(4);
    if (p) *p = (int)&self->mid.f24;
    else p = 0;
    self->mid.f24 = (int)p;
    self->mid.f28 = 0;
    self->mid.f2c = 0;
    self->mid.f30 = 0;
    self->mid.f44 = *(float*)0x9b3e60;
    int eax = *(int*)((char*)&self->mid + 0x14);
    int ebx = *(int*)&self->mid;
    if (ebx) ebx = *(int*)ebx;
    else ebx = 0;
    int v = *(int*)ebx;
    sub_57e610(&self->mid.f24, 9, eax, v);
    self->mid.f3c = 7;
    self->mid.f40 = 8;
}
