// from server: 75% by atomic.potato
extern "C" void G1_func_00414500(void*);

struct S
{
    void f(int);
};

int g_00d96870;

void S::f(int value)
{
    if (value == g_00d96870)
        return;

    g_00d96870 = value;
    G1_func_00414500((char*)this + 0x144);
}
