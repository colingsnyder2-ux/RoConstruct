// from server: 77% by atomic.potato
typedef void *P;

extern "C" void __cdecl f004e1050(P, P);
extern "C" void __cdecl f004e86e0(P);

struct S
{
    int value;
    void __cdecl f(P a, P b);
};

void __cdecl S::f(P a, P b)
{
    P t;
    f004e1050(b, &t);
    if (value != 0)
        f004e86e0(&t);
}
