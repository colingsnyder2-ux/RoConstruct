// from server: 34% by atomic.potato
struct VArcHandles_EventDesc {
    char pad[0x24];
    int field24;
    void sub_70a8c0(int);
    void f(void*, int);
};

void VArcHandles_EventDesc::f(void* a, int b) {
    if (a) {
        sub_70a8c0(b);
    } else {
        sub_70a8c0(b);
    }
}
