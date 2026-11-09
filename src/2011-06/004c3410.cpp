// from server: 100% by atomic.potato
struct S {
    char pad[0xa4];
    unsigned int field_a4;
    int f();
};

extern "C" int __cdecl sub_594180();

int S::f() {
    unsigned int q = field_a4 / 100;
    int a = (int)q;
    int b = 1;
    int* p;
    if (a > 1)
        p = &a;
    else
        p = &b;
    return sub_594180() + *p;
}
