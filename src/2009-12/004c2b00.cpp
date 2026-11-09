// from server: 36% by atomic.potato
struct S_func_00484cb0
{
    char pad0[2088];
    int m_x;
    int f();
};

int S_func_00484cb0::f()
{
    return m_x;
}

struct S_func_00580210
{
    int f();
};

struct RbxCluster
{
    char pad0[4];
    int m_4;
    int f();
};

int RbxCluster::f()
{
    if (m_4 != 0)
    {
        S_func_00484cb0 *p =
            *(S_func_00484cb0 **)((char *)this - 0x54);
        int value = p->f();
        S_func_00580210 object;
        return object.f();
    }
    return 0;
}
