// from server: 30% by atomic.potato
struct GfxAttachement {
    char pad0[0xc0];
    int field_c0;
    int field_c4;
    int method_4664d0();
    int method_9183f0(int, int, int);
    int func(int a, int b, int c);
};

int GfxAttachement::func(int a, int b, int c) {
    volatile int local = 0;
    int obj = this->method_4664d0();
    this->method_9183f0(a, b, c);
    local = local | 1;
    return a;
}
