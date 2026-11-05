// from server: 43% by atomic.potato
extern "C" {
    void* __stdcall sub_798510(void*, const void*);
    void __stdcall sub_9ea468(void*);
    void __stdcall sub_9ea400(void*);
}

struct Item_006499d0 {
    char pad_0000[0x98];
    double field_0098;
    char pad_00a0[0x1c];
    void assign(const Item_006499d0& other);
};

void Item_006499d0::assign(const Item_006499d0& other) {
    char buf[0x1c];
    sub_798510(buf, &other);
    int n = (int)(long)&other;
    double d = (double)n;
    if (n < 0) d += *(double*)0xa05248;
    field_0098 = d;
    sub_9ea468((char*)this + 0xa0);
    sub_9ea400(buf);
}
