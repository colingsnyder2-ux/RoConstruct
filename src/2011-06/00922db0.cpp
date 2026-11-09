// from server: 90% by atomic.potato
struct S
{
    int unused;
    int *object;
    int count;
    void f(int a, int b, int c);
};

void S::f(int a, int b, int c)
{
    int *vtable = *(int **)(object);
    typedef void (__thiscall *Fn)(int *, int, int);
    Fn fn = (Fn)vtable[83];
    fn(object, b, c);
    count += 3;
}
