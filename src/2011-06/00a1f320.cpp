// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1f320();
extern int sub_b_00a1f320(void*);
extern int g_b_00a1f320;

void func_00a1f320()
{
    sub_a_00a1f320();
    sub_b_00a1f320(&g_b_00a1f320);
}
