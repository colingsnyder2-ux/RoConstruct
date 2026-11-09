// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1db00();
extern int sub_b_00a1db00(void*);
extern int g_b_00a1db00;

void func_00a1db00()
{
    sub_a_00a1db00();
    sub_b_00a1db00(&g_b_00a1db00);
}
