// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd690();
extern int sub_b_00afd690(void*);
extern int g_b_00afd690;

void func_00afd690()
{
    sub_a_00afd690();
    sub_b_00afd690(&g_b_00afd690);
}
