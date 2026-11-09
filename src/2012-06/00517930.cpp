// from server: 50% by atomic.potato
struct S_func_004cc450 {
    char pad0[2120];
    int m_x;
    int f();
};

int S_func_004cc450::f()
{
    return m_x;
}

struct RbxPartBinding {
    char pad0[28];
    void* m_a;
    char pad1[52];
    unsigned char m_b;
    int f();
};

int RbxPartBinding::f()
{
    int* a = *(int**)((char*)m_a + 0x170);
    m_b = 1;
    S_func_004cc450* b = *(S_func_004cc450**)((char*)a + 0x4720);
    return b->f();
}
