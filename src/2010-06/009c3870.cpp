// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c3870();
extern int sub_b_009c3870(void*);
extern int g_b_009c3870;

void func_009c3870()
{
    sub_a_009c3870();
    sub_b_009c3870(&g_b_009c3870);
}
