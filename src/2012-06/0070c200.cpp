// from server: 48% by atomic.potato
struct S_func_0070c200
{
    int m_8;
    int m_C;

    void f(void* value, int argument);
};

void S_func_0070c200::f(void* value, int argument)
{
    if (value)
    {
        typedef void (__thiscall *Fn)(void*, int);
        Fn fn = (Fn)m_8;
        fn((void*)((char*)m_C + (long)value - 0x1c), argument);
    }
    else
    {
        typedef void (__thiscall *Fn)(void*, int);
        Fn fn = (Fn)m_8;
        fn((void*)m_C, argument);
    }
}
