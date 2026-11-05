// from server: 63% by atomic.potato
struct S {
    int f();
};
int S::f() {
    *(int*)(*(int*)this) = 0x9bcdb0;
    return 0;
}
