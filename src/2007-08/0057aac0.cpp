// from server: 100% by colin
struct S {
    virtual void v0();
    virtual char* v1();
    char* f();
};

char* S::f() {
    return v1() + 0xe8;
}
