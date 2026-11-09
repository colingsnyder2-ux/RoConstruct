// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca470();
extern int sub_b_009ca470(void*);
extern int g_b_009ca470;

void func_009ca470()
{
    sub_a_009ca470();
    sub_b_009ca470(&g_b_009ca470);
}
