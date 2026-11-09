// from server: 43% by colin
struct S {
    unsigned short field0;
    int f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
};

extern "C" int __stdcall sub_5343A0(unsigned short, int, int);
extern "C" int __stdcall sub_535330(int, int, int, int, int);
extern "C" void __stdcall sub_5360A0(void*);
extern "C" void __stdcall sub_536B10(void*, void*, void*);

int S::f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    if (a >= 0) {
        sub_5343A0(field0, b, 0);
    }
    unsigned short v = field0;
    if (v > 0x2710) {
        sub_5343A0(field0, v, 1);
    }
    field0 = v;

    char buf[8];
    sub_5360A0(buf);

    int x = *(int*)((char*)this + 0);
    int y = *(int*)((char*)this + 4);
    int z = *(int*)((char*)this + 8);
    int r = sub_535330(z, y, x, 0, 0);

    int out1;
    int out2;
    sub_536B10(this, &out1, &out2);
    return r;
}
