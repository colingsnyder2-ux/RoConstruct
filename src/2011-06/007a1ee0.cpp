// from server: 78% by atomic.potato
struct Body {
    char pad0[4];
    int field4;
    char pad8[0x2C];
    int field34;
    int field38;
    void sub_7a1ea0();
    void f(int);
};

void Body::f(int) {
    if (field34 != 0 && *(char*)(field34 + 4) != 0)
        return;
    if (field4 != 0) {
        sub_7a1ea0();
    } else if (field38 != 0) {
        *(char*)(field38 + 8) = 1;
    }
    if (field34 != 0)
        *(char*)(field34 + 4) = 1;
}
