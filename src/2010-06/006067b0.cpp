// from server: 100% by tester
struct TypedStatsItem {
    char pad[0x1dc];
    unsigned char flag;
    void sub_62ec70();
    void func();
};

void TypedStatsItem::func() {
    flag = 0;
    sub_62ec70();
}
