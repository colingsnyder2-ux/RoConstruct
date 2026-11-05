// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009caad0();
extern int sub_b_009caad0(void*);
extern int g_b_009caad0;

void func_009caad0()
{
    sub_a_009caad0();
    sub_b_009caad0(&g_b_009caad0);
}
