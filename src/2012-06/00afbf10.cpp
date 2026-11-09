// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afbf10();
extern int sub_b_00afbf10(void*);
extern int g_b_00afbf10;

void func_00afbf10()
{
    sub_a_00afbf10();
    sub_b_00afbf10(&g_b_00afbf10);
}
