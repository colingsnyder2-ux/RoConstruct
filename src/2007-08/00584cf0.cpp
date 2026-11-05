// from server: 34% by colin
// Minimal declarations for the target function.
// The function is a member of a class; ecx is set before use, so it is `this`.

struct Inner1 {
    char pad[0x20];
};

struct Inner2 {
    char pad[0x2c];
};

struct Inner3 {
    char pad[0x38];
};

struct S {
    char pad0[0x20];
    Inner1 m20;
    Inner2 m2c;
    Inner3 m38;
    void f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
};

extern "C" void __stdcall sub_5db520(void*);
extern "C" void __stdcall sub_584370(void*, void*, void*);
extern "C" void __stdcall sub_736fc0(void*, void*);
extern "C" void __stdcall sub_583ef0(void*, void*, void*);
extern "C" void __stdcall sub_583fb0(void*, void*, void*);
extern "C" void __stdcall sub_77e69c(void*, void*);
extern "C" void __stdcall sub_77e6ac(void*);

void S::f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
    char buf[0x5c];
    int v;
    char b1, b2, b3;
    int x;

    b1 = (char)a;
    b2 = (char)b;
    b3 = (char)c;
    x = d;

    buf[8] = b1;
    buf[9] = b2;
    buf[0xe] = b3;
    *(int*)(buf + 0x70) = 0;
    buf[0xf] = 0;
    *(int*)(buf + 0x7c) = x;

    sub_5db520(buf + 0x78);

    v = *(int*)(buf + 8);
    *(int*)(buf + 0x14) = v;
    *(int*)(buf + 0x14) = x;

    sub_584370(&m20, buf + 0x18, buf + 0xc);

    sub_736fc0(buf + 0x18, buf + 8);

    *(float*)(buf + 0x28) = *(float*)(buf + 0x14);
    *(float*)(buf + 0x30) = *(float*)(buf + 0x18);
    *(float*)(buf + 0x38) = *(float*)(buf + 0x20);
    *(float*)(buf + 0x3c) = *(float*)(buf + 0x28);
    *(int*)(buf + 0x2c) = x;

    sub_583ef0(&m2c, buf + 0x18, buf + 0x24);

    sub_77e69c(buf + 0x4c, buf + 0x84);
    *(int*)(buf + 0x48) = x;
    *(int*)(buf + 0x28) = *(int*)(buf + 0x44);
    sub_77e69c(buf + 0x2c, buf + 0x48);

    sub_583fb0(&m38, buf + 0x18, buf + 0x24);

    sub_77e6ac(buf + 0x28);
    sub_77e6ac(buf + 0x48);
    sub_77e6ac(buf + 0x84);
}
