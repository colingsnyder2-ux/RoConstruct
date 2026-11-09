// from server: 100% by atomic.potato
struct S
{
    int pad[5];
};

extern "C" void __cdecl f759820(S *, int);
extern "C" void __cdecl f7a799a(S *);

void __cdecl f7598b0(S *p)
{
    if (p)
    {
        f759820(p, p->pad[5]);
        f7a799a(p);
    }
}
