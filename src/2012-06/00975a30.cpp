// from server: 41% by atomic.potato
struct Sub {
    char pad[0x30];
    double get();
};

struct S {
    char pad0[0x18];
    double field18;
    char pad1[0x30 - 0x18 - 8];
    Sub sub;
    double f();
};

double S::f() {
    double a = sub.get();
    double b = field18;
    if (a == 0.0) {
        return b / a;
    }
    return (a > b) ? 1.0 : 0.0;
}
