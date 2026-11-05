// from server: 0% by atomic.potato
struct S {
    int f(int a, int b);
};

extern "C" void* __stdcall sub_80a334();
extern "C" void* __stdcall sub_80a32e();
extern "C" void* __stdcall sub_80a322();
extern "C" void* __stdcall sub_423250(int);
extern "C" void* __stdcall sub_42e040(void*, void*);
extern "C" void* __stdcall sub_40a000(void*);
extern "C" void* __stdcall sub_40a090(void*);
extern "C" void* __stdcall sub_5b2280(void*, void*, int, void*);

extern "C" void* __stdcall imp_a42db4();
extern "C" void* __stdcall imp_a42db8();
extern "C" void* __stdcall imp_a42dbc();
extern "C" void* __stdcall imp_a42dc8();
extern "C" void* __stdcall imp_a42e08();
extern "C" void* __stdcall imp_a404bc();
extern "C" void* __stdcall imp_a404d0();

extern void* g_a5ea64;
extern void* g_a6db14;

int S::f(int a, int b)
{
    void* p;
    char buf[0x60];
    char buf2[0x58];
    void* v;
    void* w;
    void* x;
    void* y;
    int r;

    sub_80a334();
    sub_80a32e();
    p = sub_423250(b);
    if (p) {
        imp_a42db4();
        imp_a42db8();
        imp_a42dbc();
        imp_a42e08();
        imp_a42dc8();
        r = (int)sub_42e040(&g_a6db14, 0);
        imp_a42e08();
        return r;
    }
    imp_a404bc();
    imp_a42db8();
    imp_a42dc8();
    sub_40a000(buf2);
    sub_5b2280(buf, (char*)a + 8, 1, buf2);
    sub_40a090(buf2);
    imp_a42e08();
    imp_a404d0();
    return 0;
}
