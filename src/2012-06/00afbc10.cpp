// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afbc10();
extern int sub_b_00afbc10(void*);
extern int g_b_00afbc10;

void func_00afbc10()
{
    sub_a_00afbc10();
    sub_b_00afbc10(&g_b_00afbc10);
}
