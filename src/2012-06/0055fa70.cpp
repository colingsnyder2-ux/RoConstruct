// from server: 100% by atomic.potato
extern "C" int __cdecl sub_00680ca0();

struct S_0055fa70 {
    char pad_0[0xac];
    unsigned int f_ac;
    int get();
};

int S_0055fa70::get() {
    unsigned int q = f_ac / 100;
    int a = (int)q;
    int b = 1;
    int* p;
    if (a > 1) {
        p = &a;
    } else {
        p = &b;
    }
    return sub_00680ca0() + *p;
}
