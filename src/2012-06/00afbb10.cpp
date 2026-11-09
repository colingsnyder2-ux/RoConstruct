// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afbb10();
extern int sub_b_00afbb10(void*);
extern int g_b_00afbb10;

void func_00afbb10()
{
    sub_a_00afbb10();
    sub_b_00afbb10(&g_b_00afbb10);
}
