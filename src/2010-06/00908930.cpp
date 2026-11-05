// from server: 55% by atomic.potato
struct S_func_008cc5e0 {
    char pad0[2096];
    int m_x;
    int f();
};

int S_func_008cc5e0::f()
{
    return m_x;
}

struct S_func_00908930 {
    char pad0[4];
    int m_x;
    int f();
};

int S_func_00908930::f()
{
    if (m_x != 0) {
        S_func_008cc5e0 *a = *(S_func_008cc5e0 **)((char *)this - 0x54);
        int b = *(int *)((char *)a + 0x47e0);
        int value = (((char *)this - 0x238) != 0) ? (int)this : 0;
        a = (S_func_008cc5e0 *)b;
        a->f();
        return value;
    }
    return 0;
}
