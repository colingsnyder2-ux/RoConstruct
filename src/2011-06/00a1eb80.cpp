// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1eb80();
extern int sub_b_00a1eb80(void*);
extern int g_b_00a1eb80;

void func_00a1eb80()
{
    sub_a_00a1eb80();
    sub_b_00a1eb80(&g_b_00a1eb80);
}
