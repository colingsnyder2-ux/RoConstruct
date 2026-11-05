// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb210();
extern int sub_b_009cb210(void*);
extern int g_b_009cb210;

void func_009cb210()
{
    sub_a_009cb210();
    sub_b_009cb210(&g_b_009cb210);
}
