// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1e240();
extern int sub_b_00a1e240(void*);
extern int g_b_00a1e240;

void func_00a1e240()
{
    sub_a_00a1e240();
    sub_b_00a1e240(&g_b_00a1e240);
}
