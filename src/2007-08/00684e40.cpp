// from server: 100% by colin
struct S {
    int pad[13];
    int value;
    int f();
};

int S::f() {
    value = 1;
    return 1;
}
