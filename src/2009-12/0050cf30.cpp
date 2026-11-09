// from server: 4% by atomic.potato
struct C1 {
    char pad[0x30];
    void f(int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

struct C2 {
    void f();
};

struct C3 {
    void f();
};

struct S {
    char pad[0x30];
    void method(int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

void C1::f(int, int, int, int, int, int, int, int, int, int, int, int, int, int) {}
void C2::f() {}
void C3::f() {}

void S::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
    char buf[0x34];
    C1 c1;
    C2 c2;
    C3 c3;
    c1.f(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
    *(char*)(buf + 0x2c) = (char)a14;
    c2.f();
    c3.f();
}
