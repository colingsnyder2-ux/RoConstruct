// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1f300();
extern int sub_b_00a1f300(void*);
extern int g_b_00a1f300;

void func_00a1f300()
{
    sub_a_00a1f300();
    sub_b_00a1f300(&g_b_00a1f300);
}
