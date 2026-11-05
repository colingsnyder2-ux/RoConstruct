// from server: 67% by atomic.potato
struct TypedStatsItem {
    char pad[0xc0];
    float sub_4f4f70();
    void sub_649b00(float*);
    void func();
};

void TypedStatsItem::func() {
    float value = sub_4f4f70();
    sub_649b00(&value);
}
