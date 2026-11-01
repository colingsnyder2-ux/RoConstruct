// from server: 100% by colin
struct ClumpStage {
    void sub_6083B0(int);
    void sub_608420(int);
    void sub_609140(int);
    void func(int);
};

void ClumpStage::func(int a) {
    int v = *(int*)(a + 0x6c);
    if (v != 0) {
        sub_6083B0(v);
    }
    sub_608420(a);
    ((ClumpStage*)a)->sub_609140((int)this);
}
