// from server: 100% by why2
struct S {
    char pad[0x96];
    short field_96;
    int helper();
    int f();
};

int S::f() {
    helper();
    return field_96;
}
