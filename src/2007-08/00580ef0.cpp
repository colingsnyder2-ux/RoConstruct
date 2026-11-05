// from server: 100% by colin
struct Sub {
    char pad[0x14];
    void destroy();
};

struct Accoutrement {
    char pad[0x150];
    Sub a;
    Sub b;
    void f();
};

void Accoutrement::f() {
    a.destroy();
    b.destroy();
}
