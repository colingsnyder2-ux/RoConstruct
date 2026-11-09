// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afbc30();
extern int sub_b_00afbc30(void*);
extern int g_b_00afbc30;

void func_00afbc30()
{
    sub_a_00afbc30();
    sub_b_00afbc30(&g_b_00afbc30);
}
