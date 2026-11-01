// from server: 100% by atomic.potato
struct VStockSound {
    char pad[0x120];
    int field_120;
    void sub_58c1b0(void*);
    void sub_444710(int);
    void FactoryProduct();
};

void VStockSound::FactoryProduct() {
    sub_58c1b0(this);
    int v = field_120 + 1;
    int a = 1;
    int* p;
    if (v < 1) {
        p = &a;
    } else {
        p = &v;
    }
    int r = *p;
    field_120 = r;
    sub_444710(0x8c33e8);
}
