// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afbc50();
extern int sub_b_00afbc50(void*);
extern int g_b_00afbc50;

void func_00afbc50()
{
    sub_a_00afbc50();
    sub_b_00afbc50(&g_b_00afbc50);
}
