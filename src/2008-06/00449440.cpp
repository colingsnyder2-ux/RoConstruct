// from server: 100% by atomic.potato
int g_value;

struct S
{
    int f();
    char padding[0x130];
    int value;
};

int S::f()
{
    if (!g_value)
        g_value = value;
    return g_value;
}
