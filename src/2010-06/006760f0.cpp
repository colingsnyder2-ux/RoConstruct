// from server: 56% by atomic.potato
struct S_func_007d2540
{
    char pad0[32];
    int m_x;
    int f();
};

int S_func_007d2540::f()
{
    return m_x;
}

struct S_EventDesc
{
    int f();
};

int S_EventDesc::f()
{
    S_func_007d2540* p = *(S_func_007d2540**)((char*)this + 4);
    p = (S_func_007d2540*)((char*)p + 8);
    int result = p->f();
    result = ((S_func_007d2540*)result)->f();
    if (result)
        return result - 8;
    return 0;
}
