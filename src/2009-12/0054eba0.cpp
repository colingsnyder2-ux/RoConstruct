// from server: 55% by atomic.potato
struct S {
    int f(int);
};

int S::f(int a)
{
    int (*p)(int) = *(int (**)(int))(*(int **)this + 0x74);
    return p(a);
}
