// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afccf0();
extern int sub_b_00afccf0(void*);
extern int g_b_00afccf0;

void func_00afccf0()
{
    sub_a_00afccf0();
    sub_b_00afccf0(&g_b_00afccf0);
}
