// from server: 54% by atomic.potato
struct S {
    char pad[4];
    int field4;
    int f(int a, int b);
};

extern "C" void __stdcall sub_4c1670(int, int);

extern "C" int __stdcall sub_6be3a0(int, int, int);

int S::f(int a, int b) {
    sub_4c1670(1, 0);
    field4 = 0;
    sub_6be3a0((int)this, a, b);
    return a;
}
