// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cacf0();
extern int sub_b_009cacf0(void*);
extern int g_b_009cacf0;

void func_009cacf0()
{
    sub_a_009cacf0();
    sub_b_009cacf0(&g_b_009cacf0);
}
