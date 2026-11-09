// from server: 60% by atomic.potato
struct EventDesc {
    char pad0[4];
    char pad1[4];
    int sub_4c1670(int);
    int sub_5ad4f0(int, int);
    int f(int, int);
};

int EventDesc::f(int a, int b) {
    int local = 0;
    this->sub_4c1670(1);
    this->sub_5ad4f0(a, b);
    return a;
}
