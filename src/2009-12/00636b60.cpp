// from server: 39% by atomic.potato
struct EventDesc {
    char pad[0x34];
    int field34;
    void sub_636330(int);

    void method(int a, int b);
};

void EventDesc::sub_636330(int) {}

void EventDesc::method(int a, int b) {
    if (a) {
        this->field34 += a - 0x1c;
        sub_636330(b);
    } else {
        this->field34 += 0;
        sub_636330(b);
    }
}
