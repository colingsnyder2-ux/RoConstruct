// from server: 34% by atomic.potato
struct Inner {
    char pad0[4];
    void sub_6d2650(int, int);
};

struct Outer {
    int f(int, int);
};

extern "C" void __stdcall sub_75a4e0(void*, int, int);

int Outer::f(int a, int b)
{
    Inner* p = (Inner*)a;
    *(int*)this = a;
    p->sub_6d2650(b, a);
    int t = 0;
    if (a != 0)
        t = a + 0x20;
    sub_75a4e0((char*)this + 4, t, a);
    return (int)this;
}
