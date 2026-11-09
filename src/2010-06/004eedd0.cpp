// from server: 57% by atomic.potato
struct S
{
    int f;
    int g;
};

extern "C" S* __cdecl G1_func_004ee600(S*);

S* __cdecl G1_func_004eedb0(S* p)
{
    S* q = G1_func_004ee600(p);
    p->f = q->f;
    return p;
}
