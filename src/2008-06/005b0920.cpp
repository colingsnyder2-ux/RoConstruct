// from server: 100% by tester
struct Sub {
    char pad[0x14];
    void destroy();
};

struct Accoutrement {
    char pad[0x19c];
    Sub a;
    Sub b;
    void f();
};

void Accoutrement::f() {
    a.destroy();
    b.destroy();
}
