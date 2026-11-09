// from server: 76% by atomic.potato
extern "C" void __cdecl sub_629c20(int, int);

int g_00c2c3d8;

struct S
{
    int f(int);
};

int S::f(int value)
{
    int local = 0;
    int old = g_00c2c3d8;
    local = old;
    ++old;
    g_00c2c3d8 = old;
    sub_629c20(value, (int)&local);
    return value;
}
