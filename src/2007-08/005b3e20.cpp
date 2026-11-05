// from server: 100% by colin
struct Inner {
    int calc(int* p);
};

struct Outer {
    char pad[0x40];
    Inner inner;
    int f(int a);
};

int Outer::f(int a) {
    return inner.calc(&a);
}
