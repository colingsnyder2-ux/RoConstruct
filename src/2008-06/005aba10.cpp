// from server: 100% by colin
struct S { int (__cdecl *f)(int); };

int invoke(S* s, int x)
{
    return s->f(x);
}
