// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009caab0();
extern int sub_b_009caab0(void*);
extern int g_b_009caab0;

void func_009caab0()
{
    sub_a_009caab0();
    sub_b_009caab0(&g_b_009caab0);
}
