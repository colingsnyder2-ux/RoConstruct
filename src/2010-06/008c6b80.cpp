// from server: 84% by atomic.potato
struct S {
    int pad;
    int *p;
    int count;
    void f(int a, int b, int c);
};

void S::f(int a, int b, int c)
{
    int *v = p;
    typedef void (__thiscall *Fn)(int *, int, int);
    Fn fn = *(Fn *)(*(int **)v + 0x13c);
    fn(v, b, c);
    count += 3;
}
