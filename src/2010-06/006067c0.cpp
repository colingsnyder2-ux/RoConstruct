// from server: 100% by atomic.potato
struct TypedStatsItem {
    char pad0[0x140];
    void* value;
    char pad1[0x98];
    unsigned char flag;
    void sub_605a50();
    void func();
};

void TypedStatsItem::func() {
    flag = 0;
    sub_605a50();
    *((int*)((char*)value + 0x54)) = 0;
}
