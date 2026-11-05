// from server: 44% by atomic.potato
struct S_func_0092b620 {
    char pad0[2120];
    int m_x;
    int f();
};

int S_func_0092b620::f()
{
    return m_x;
}

extern int func_0092b620();

extern int func_0096e1b0(int);

struct S_func_00966290 {
    char pad0[4];
    int m_flag;
    char pad8[0x50];
    int m_parent;
    int f();
};

int S_func_00966290::f()
{
    if (m_flag != 0) {
        int value = *(int *)(*(int *)((char *)this - 0x54) + 0x4880);
        int argument = ((int)this - 0x1c4 == 0) ? (int)this : 0;
        return func_0096e1b0(func_0092b620());
    }
    return 0;
}
