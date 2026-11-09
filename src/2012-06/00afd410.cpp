// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd410();
extern int sub_b_00afd410(void*);
extern int g_b_00afd410;

void func_00afd410()
{
    sub_a_00afd410();
    sub_b_00afd410(&g_b_00afd410);
}
