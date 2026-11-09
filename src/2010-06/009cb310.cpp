// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb310();
extern int sub_b_009cb310(void*);
extern int g_b_009cb310;

void func_009cb310()
{
    sub_a_009cb310();
    sub_b_009cb310(&g_b_009cb310);
}
