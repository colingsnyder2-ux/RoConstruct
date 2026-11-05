// from server: 46% by atomic.potato
struct S
{
    int value;
};

extern "C" void __fastcall f(S *, int *, int *);

void g()
{
    int a;
    int b;
    S *p;

    a = 0;
    b = 0;
    f((S *)((char *)p + 4), &a, &b);
}
