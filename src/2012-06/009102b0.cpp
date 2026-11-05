// from server: 100% by tajop
extern void G1_func_00910180(void *, int);
extern void G1_func_00982114(void *);

void __cdecl G1_func_009102b0(void *p)
{
    if (p)
    {
        G1_func_00910180(p, *(int *)((char *)p + 12));
        G1_func_00982114(p);
    }
}