// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afb500();
extern int sub_b_00afb500(void*);
extern int g_b_00afb500;

void func_00afb500()
{
    sub_a_00afb500();
    sub_b_00afb500(&g_b_00afb500);
}
