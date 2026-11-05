// from server: 51% by atomic.potato
struct S
{
    int f(float, float, float);
    int (__thiscall *v)(int, float, float);
};

int S::f(float a, float b, float c)
{
    return v( v(0, c, b), a, b);
}
