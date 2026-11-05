// from server: 52% by atomic.potato
struct S
{
    int (**vtable)();
    void f(double, void *);
};

void S::f(double value, void *arg)
{
    int (__thiscall **table)(int, int, void *, double) =
        (int (__thiscall **) (int, int, void *, double))vtable;
    table[5](0, 0, arg, value);
}
