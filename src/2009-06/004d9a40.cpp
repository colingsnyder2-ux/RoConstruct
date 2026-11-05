// from server: 100% by why2
struct S {
    void f(int n);
    char pad[8];
    int field_8;
};

void S::f(int n) {
    field_8 += n * 8;
}
