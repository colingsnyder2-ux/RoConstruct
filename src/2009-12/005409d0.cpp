// from server: 62% by atomic.potato
struct S
{
    int v0;
    int v1;
};

extern "C" S* __cdecl f00540190(S*);

struct R
{
};

S* __cdecl f(S* p)
{
    S* q = f00540190(p);
    p->v0 = q->v0;
    p->v1 = q->v1;
    return p;
}
