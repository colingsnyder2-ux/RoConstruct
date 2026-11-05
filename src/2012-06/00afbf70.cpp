// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afbf70();
extern int sub_b_00afbf70(void*);
extern int g_b_00afbf70;

void func_00afbf70()
{
    sub_a_00afbf70();
    sub_b_00afbf70(&g_b_00afbf70);
}
