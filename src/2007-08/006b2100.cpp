// from server: 37% by colin
struct CXTPRibbonTheme {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int sub_6B2100(int* src, int* dst, int a, int b, int c, int d);
};

struct Inner {
    int a;
    int b;
    int c;
    int d;
};

extern "C" void __stdcall sub_710520(void*, void*);
extern "C" int __cdecl sub_6AD860(void*);
extern "C" void __stdcall sub_642FA0(void*, void*, int);

int CXTPRibbonTheme::sub_6B2100(int* src, int* dst, int a, int b, int c, int d)
{
    field0 = src[0];
    field4 = src[1];
    field8 = src[2];
    fieldC = src[3];

    int local[4];
    sub_710520(&local, dst);
    if (sub_6AD860(this)) {
        Inner inner;
        inner.a = *(int*)((char*)this + 0xC0);
        inner.b = *(int*)((char*)this + 0xC4);
        inner.c = *(int*)((char*)this + 0xC8);
        inner.d = *(int*)((char*)this + 0xCC);
        sub_642FA0(&inner, dst, 0);
    }

    int* out = (int*)((char*)&local + 0x0C);
    out[1] = b;
    out[0] = b;
    return 0;
}
