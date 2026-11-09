// from server: 48% by atomic.potato
extern "C" void __cdecl Function_0064f690(void *, void *);

struct S_func_0068ce00 {
    char pad0[36];
    float m_x;
    float m_y;
    float m_z;
    void *f(void *arg);
};

void *S_func_0068ce00::f(void *arg)
{
    float v[3];
    v[0] = m_x;
    v[1] = m_y;
    v[2] = m_z;
    Function_0064f690(arg, v);
    return arg;
}
