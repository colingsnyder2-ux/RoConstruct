// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afcd70();
extern int sub_b_00afcd70(void*);
extern int g_b_00afcd70;

void func_00afcd70()
{
    sub_a_00afcd70();
    sub_b_00afcd70(&g_b_00afcd70);
}
