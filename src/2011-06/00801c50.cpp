// from server: 59% by atomic.potato
struct S
{
    S * __cdecl f(S *, int);
};

extern "C" S *__cdecl sub_801df0(S *, int);

S *S::f(S *a, int b)
{
    sub_801df0(a, b);
    return a;
}
