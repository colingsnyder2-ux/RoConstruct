// from server: 84% by atomic.potato
extern "C" void __cdecl free(void*);

struct S
{
    S* f(int);
};

S* S::f(int a)
{
    S* p = this;
    p->f(0);
    if ((a & 1) != 0)
        free((char*)p - 4);
    return p;
}
