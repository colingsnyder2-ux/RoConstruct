// from server: 100% by atomic.potato
struct S
{
    int value;
    int *object;
    int offset;
    int f(int amount);
};

int S::f(int amount)
{
    int *vtable = *(int **)object;
    typedef void (__thiscall *Fn)(int *, int);
    Fn fn = (Fn)vtable[61];
    fn(object, offset + amount);
    return offset;
}
