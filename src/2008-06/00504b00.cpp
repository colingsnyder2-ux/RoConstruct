// from server: 100% by king_originala
struct A {
    char data[12];
    void reset(void*, void*);
};

struct B {
    char data[12];
    void reset(void*, void*);
};

struct C {
    void reset(void*, void*);
};

struct S {
    char padding[0x268];
    B b268;
    A a274;
    A a280;
    A a28c;
    B b298;
    C c2a4;

    void f();
};

void S::f()
{
    a274.reset(0, 0);
    b298.reset(0, 0);
    a280.reset(0, 0);
    a28c.reset(0, 0);
    b268.reset(0, 0);
    c2a4.reset(0, 0);
}
