// from server: 100% by tajop
extern void G1_func_008a9250(void *, int);
extern void G1_func_00982114(void *);

void __cdecl G1_func_008a9590(void *p)
{
    if (p)
    {
        G1_func_008a9250(p, *(int *)((char *)p + 12));
        G1_func_00982114(p);
    }
}