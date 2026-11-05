// from server: 100% by colin
struct Inner {
    void sub_63B850(int, int, int);
};

struct Outer {
    char pad0[0x20];
    Inner inner;
    char pad1[0x2C];
    void sub_661820(int);
    void target(int, int);
};

void Outer::target(int a, int b)
{
    inner.sub_63B850(a, b, 1);
    *(Outer**)(b + 0x50) = this;
    sub_661820(a);
}
