// from server: 14% by atomic.potato
typedef int (__thiscall *Callback)(void *, int, int, int, int);

struct S
{
    int f(int, int, int, int);
};

int S::f(int a, int b, int c, int d)
{
    Callback p = *(Callback *)(*(int *)this + 0x38);
    return p(this, a, a, b, c);
}
