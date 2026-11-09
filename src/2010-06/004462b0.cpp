// from server: 60% by atomic.potato
struct S
{
    S *f(void *);
};

void *g(void *, int, void *);

S *S::f(void *p)
{
    void *v;
    return (S *)g(this, ((int (__thiscall *)(void *, void *))(*(int **)(*(int **)((char *)this + 0x1c)) + 0xc))( *(void **)((char *)this + 0x1c), &v), p);
}
