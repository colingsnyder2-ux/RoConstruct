// from server: 34% by atomic.potato
struct EventDesc {
    char pad[0x38];
    int field38;
    void sub_59df70(int);
    void f(int, int);
};

void EventDesc::f(int a, int b) {
    if (a) {
        sub_59df70(b);
    } else {
        sub_59df70(b);
    }
}
