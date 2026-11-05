// from server: 34% by atomic.potato
struct EventDesc {
    char pad[0x34];
    int field34;
    void sub_543DA0(int);
    void f(int, int);
};

void EventDesc::f(int a, int b) {
    if (a) {
        sub_543DA0(b);
    } else {
        sub_543DA0(b);
    }
}
