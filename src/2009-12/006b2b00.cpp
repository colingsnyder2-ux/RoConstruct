// from server: 100% by atomic.potato
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
