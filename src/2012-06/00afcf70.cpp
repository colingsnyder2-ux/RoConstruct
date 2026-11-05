// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afcf70();
extern int sub_b_00afcf70(void*);
extern int g_b_00afcf70;

void func_00afcf70()
{
    sub_a_00afcf70();
    sub_b_00afcf70(&g_b_00afcf70);
}
