// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca6d0();
extern int sub_b_009ca6d0(void*);
extern int g_b_009ca6d0;

void func_009ca6d0()
{
    sub_a_009ca6d0();
    sub_b_009ca6d0(&g_b_009ca6d0);
}
