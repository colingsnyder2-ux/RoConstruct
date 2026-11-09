// from server: 19% by atomic.potato
struct S
{
    void __cdecl f(void *);
};

extern "C" void __stdcall call_004f4b40(void *, void *);

void S::f(void *p)
{
    void *v = p;
    call_004f4b40(v, &p);
}
