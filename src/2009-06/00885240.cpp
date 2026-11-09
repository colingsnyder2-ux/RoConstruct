// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00885240();
extern int sub_b_00885240(void*);
extern int g_b_00885240;

void func_00885240()
{
    sub_a_00885240();
    sub_b_00885240(&g_b_00885240);
}
