// from server: 100% by tajop
extern void G1_func_00915d40(void *, int);
extern void G1_func_00982114(void *);

void __cdecl G1_func_00915e70(void *p)
{
    if (p)
    {
        G1_func_00915d40(p, *(int *)((char *)p + 12));
        G1_func_00982114(p);
    }
}