// from server: 66% by atomic.potato
extern "C" int __cdecl sub_004c0590(void *);

struct S_func_005e6030 {
    char pad0[36];
    void *m_data;
    int f(int value);
};

int S_func_005e6030::f(int value)
{
    if (value)
        return sub_004c0590((char *)m_data + value - 28);
    return sub_004c0590(m_data);
}
