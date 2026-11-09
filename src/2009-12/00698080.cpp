// from server: 64% by atomic.potato
struct S
{
    typedef void (__thiscall *F)(void *, int);
};

void __cdecl f(void *p)
{
    S::F fn = *(S::F *)*(unsigned long *)p;
    fn(*(void **)((char *)p + 4), *(int *)((char *)p + 8));
}
