// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc410();
extern int sub_b_00afc410(void*);
extern int g_b_00afc410;

void func_00afc410()
{
    sub_a_00afc410();
    sub_b_00afc410(&g_b_00afc410);
}
