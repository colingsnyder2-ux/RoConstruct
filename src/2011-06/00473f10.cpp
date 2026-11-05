// from server: 72% by atomic.potato
struct S
{
    int (**p)(int);
    int __cdecl f(int);
};

int S::f(int x)
{
    return (**p)(x);
}
