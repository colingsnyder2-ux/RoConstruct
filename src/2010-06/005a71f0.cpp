// from server: 65% by atomic.potato
struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(int, int, int*);
};

struct Outer {
    char pad[0x1c];
    Inner* inner;
    int method(int, int);
};

extern "C" void __cdecl sub_620730(int, int);

int Outer::method(int a, int b)
{
    int result = 0;
    int r = inner->f4(a, b, &result);
    sub_620730(r, 0);
    return r;
}
