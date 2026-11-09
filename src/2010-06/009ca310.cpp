// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca310();
extern int sub_b_009ca310(void*);
extern int g_b_009ca310;

void func_009ca310()
{
    sub_a_009ca310();
    sub_b_009ca310(&g_b_009ca310);
}
