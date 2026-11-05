// from server: 85% by atomic.potato
extern "C" int __fastcall sub_00594180();

struct S_004e5c50 {
    char pad_0[0xb8];
    unsigned int f_b8;
    int get();
};

int S_004e5c50::get() {
    unsigned int q = (unsigned int)(((unsigned long long)f_b8 * 0x51eb851fULL) >> 32) >> 5;
    int a = (int)q;
    int b = 1;
    int* p;
    if (a > 1) {
        p = &a;
    } else {
        p = &b;
    }
    return sub_00594180() + *p;
}
