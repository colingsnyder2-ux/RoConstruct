// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afcbf0();
extern int sub_b_00afcbf0(void*);
extern int g_b_00afcbf0;

void func_00afcbf0()
{
    sub_a_00afcbf0();
    sub_b_00afcbf0(&g_b_00afcbf0);
}
