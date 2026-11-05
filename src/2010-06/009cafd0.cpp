// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cafd0();
extern int sub_b_009cafd0(void*);
extern int g_b_009cafd0;

void func_009cafd0()
{
    sub_a_009cafd0();
    sub_b_009cafd0(&g_b_009cafd0);
}
