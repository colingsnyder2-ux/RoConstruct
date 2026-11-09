// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afcdb0();
extern int sub_b_00afcdb0(void*);
extern int g_b_00afcdb0;

void func_00afcdb0()
{
    sub_a_00afcdb0();
    sub_b_00afcdb0(&g_b_00afcdb0);
}
