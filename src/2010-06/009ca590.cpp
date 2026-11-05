// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca590();
extern int sub_b_009ca590(void*);
extern int g_b_009ca590;

void func_009ca590()
{
    sub_a_009ca590();
    sub_b_009ca590(&g_b_009ca590);
}
