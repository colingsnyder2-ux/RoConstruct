// from server: 41% by atomic.potato
struct S
{
    struct V
    {
        int (**f)(int);
    };

    V *p;
    int f(int);
};

extern "C" int __cdecl sub_443af0(S *, int, int);

int S::f(int a)
{
    int b = (*p->f)(a);
    return sub_443af0(this, b, 0);
}
