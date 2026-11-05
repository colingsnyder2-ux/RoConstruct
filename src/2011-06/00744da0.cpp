// from server: 45% by atomic.potato
struct EventDesc {
    char pad0[4];
    char pad1[4];
    void sub_4c1670(int);
    int sub_744720(int, int);
    int f(int, int);
};

int EventDesc::f(int a, int b) {
    sub_4c1670(1);
    return sub_744720(a, b);
}
