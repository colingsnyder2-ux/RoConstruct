// from server: 100% by colin
struct VStockSound {
    char pad[0x168];
    int field168;
    void method();
};

struct VMember {
    void set(const char*);
};

extern "C" void __stdcall sub_5bceb0(void*);

void VStockSound::method() {
    sub_5bceb0(this);
    int v = field168 + 1;
    int one = 1;
    int* p;
    if (v < 1)
        p = &one;
    else
        p = &v;
    field168 = *p;
    ((VMember*)this)->set((const char*)0x977010);
}
