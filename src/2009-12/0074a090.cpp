// from server: 11% by atomic.potato
struct EventDesc {
    char pad[0x34];
    int field34;
    void sub_749E30(int);

    void method(int a, int b);
};

void EventDesc::sub_749E30(int) {}

void EventDesc::method(int a, int b) {
    if (a) {
        sub_749E30(b);
    } else {
        sub_749E30(b);
    }
}
