// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca410();
extern int sub_b_009ca410(void*);
extern int g_b_009ca410;

void func_009ca410()
{
    sub_a_009ca410();
    sub_b_009ca410(&g_b_009ca410);
}
