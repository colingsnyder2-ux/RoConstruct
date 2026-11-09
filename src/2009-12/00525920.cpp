// from server: 100% by atomic.potato
struct S_func_00525920 {
    unsigned char f();
};

struct S_func_005256e0_result {
    char pad0[0x266c];
    unsigned char value;
};

S_func_005256e0_result *S_func_005256e0();

unsigned char S_func_00525920::f()
{
    S_func_005256e0_result *p = S_func_005256e0();
    if (p)
        return p->value;
    return 0;
}
