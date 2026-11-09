// from server: 41% by atomic.potato
struct S_func_006dcd40
{
    int f();
};

struct S_func_00695f70
{
    char pad0[288];
    S_func_006dcd40 m_field;
    int f(int value);
};

int S_func_00695f70::f(int value)
{
    m_field.f();
    return 0;
}
