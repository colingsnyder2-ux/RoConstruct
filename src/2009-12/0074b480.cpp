// from server: 38% by atomic.potato
extern "C" unsigned int __cdecl sub_71f670(unsigned int);

struct S_func_006b2b00 {
    unsigned int m_flags;
    void f(unsigned int value, bool set);
};

void S_func_006b2b00::f(unsigned int value, bool set)
{
    if (set)
        m_flags |= sub_71f670(value);
    else
        m_flags &= ~sub_71f670(value);
}

struct S_func_006b2dc0 {
    int m_value;
    S_func_006b2dc0(int v);
};

S_func_006b2dc0::S_func_006b2dc0(int v)
{
    m_value = v;
}

struct S_func_006b2e30 {
    bool f(int index);
};

struct ArcHandles {
    char pad[0x1bc];
    S_func_006b2e30 m_handles;
    int m_result;
    int f();
};

int ArcHandles::f()
{
    S_func_006b2dc0 local(0);
    m_result = 0;
    m_handles.f(0);
    m_result = 0;
    m_handles.f(1);
    m_result = 0;
    m_handles.f(2);
    return m_result;
}
