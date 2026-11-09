// from server: 100% by tester
struct S {
    virtual void v0();
    virtual char* v1();
    char* f();
};

char* S::f() {
    return v1() + 0xf0;
}