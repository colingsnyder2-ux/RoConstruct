// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00aeeb10();
extern int sub_b_00aeeb10(void*);
extern int g_b_00aeeb10;

void func_00aeeb10()
{
    sub_a_00aeeb10();
    sub_b_00aeeb10(&g_b_00aeeb10);
}
