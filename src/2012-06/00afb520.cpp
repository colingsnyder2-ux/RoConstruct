// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afb520();
extern int sub_b_00afb520(void*);
extern int g_b_00afb520;

void func_00afb520()
{
    sub_a_00afb520();
    sub_b_00afb520(&g_b_00afb520);
}
