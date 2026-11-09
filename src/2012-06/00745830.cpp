// from server: 59% by atomic.potato
extern "C" int __cdecl G1_func_00742aa0(void *, void *);

int __cdecl func_00745830(void *a, void *b, int *c)
{
    void *p;
    if (*(unsigned int *)((char *)a + 0x18) >= 0x10)
        p = *(void **)((char *)a + 4);
    else
        p = (char *)a + 4;

    G1_func_00742aa0(&p, b);
    *c = *(int *)p;
    return 1;
}
