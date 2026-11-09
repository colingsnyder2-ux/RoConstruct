// from server: 45% by atomic.potato
struct EventDesc {
    char pad0[4];
    char pad1[4];
    void sub_4c1670(int);
    int sub_4c18a0(int, int);
    int init(int, int);
};

int EventDesc::init(int a, int b) {
    sub_4c1670(1);
    return sub_4c18a0(a, b);
}
