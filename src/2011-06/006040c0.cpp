// from server: 100% by atomic.potato
extern int g_value;

struct S
{
    int f();
};

int S::f()
{
    return g_value == 1;
}
