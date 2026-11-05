// from server: 50% by atomic.potato
struct EventDesc {
    char pad0[4];
    char pad1[4];
    void sub_4c1670(int);
    void sub_4c1b40(int, int);
    int init(int, int);
};

int EventDesc::init(int a, int b) {
    char local = 0;
    sub_4c1670(1);
    sub_4c1b40(b, a);
    return a;
}
