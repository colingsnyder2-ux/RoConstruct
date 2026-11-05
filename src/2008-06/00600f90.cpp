// from server: 100% by EspClaude
// roc 2008-06 00600f90  size: 180 bytes

struct P0 {
    virtual void f0();
    char pad[12];
};

struct P10 {
    virtual void f10();
};

struct P14 {
    virtual void f14();
    char pad[8];
};

struct P20 {
    virtual void f20();
};

struct P24 {
    virtual void f24();
    char pad[28];
};

struct P44 {
    virtual void f44();
    char pad[28];
};

struct P64 {
    virtual void f64();
    char pad[28];
};

struct P84 {
    virtual void f84();
    char pad[28];
};

struct Pa4 {
    virtual void fa4();
    char pad[28];
};

struct Pc4 {
    virtual void fc4();
    char pad[104];
};

struct P130 {
    virtual void f130();
    char pad[48];
};

struct B : P0, P10, P14, P20, P24, P44, P64, P84, Pa4, Pc4, P130 {
    B();
    ~B();
};

struct S : B {
    struct Flags {
        unsigned short a, b;
        Flags() : a(0), b(0) {}
    } flags;
    S(int);
    void g(int);
};

S::S(int argument)
    : B()
{
    g(argument);
}
