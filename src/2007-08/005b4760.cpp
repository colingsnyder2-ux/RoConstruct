// from server: 100% by colin
struct S {
    int pad0;
    int pad4;
    int field8;
    int padc;
    int field10;
    int f();
};

int S::f() {
    int r = field10;
    if (r == 0) r = field8;
    return r;
}
