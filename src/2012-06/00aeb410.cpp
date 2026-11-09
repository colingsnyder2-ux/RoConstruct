// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00aeb410();
extern int sub_b_00aeb410(void*);
extern int g_b_00aeb410;

void func_00aeb410()
{
    sub_a_00aeb410();
    sub_b_00aeb410(&g_b_00aeb410);
}
