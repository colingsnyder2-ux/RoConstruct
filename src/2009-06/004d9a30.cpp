// from server: 100% by why2
struct S {
    void f(int);
    char pad[8];
    int field_8;
};

void S::f(int a) {
    field_8 += a;
}
