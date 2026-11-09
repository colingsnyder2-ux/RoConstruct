// from server: 100% by why2
struct S {
    int pad0;
    int pad4;
    int field8;
    int fieldC;
    void f();
};

void S::f() {
    field8 = 0;
    fieldC = 0;
}
