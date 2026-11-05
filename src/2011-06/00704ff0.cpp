// from server: 100% by atomic.potato
struct S_func_00704ff0 {
    char pad0[12];
    void (__thiscall *m_call)(void *, void *, float);
    void *m_arg;
    void f(void *arg, float value);
};

void S_func_00704ff0::f(void *arg, float value)
{
    m_call(m_arg, arg, value);
}
