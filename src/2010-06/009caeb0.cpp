// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009caeb0();
extern int sub_b_009caeb0(void*);
extern int g_b_009caeb0;

void func_009caeb0()
{
    sub_a_009caeb0();
    sub_b_009caeb0(&g_b_009caeb0);
}
