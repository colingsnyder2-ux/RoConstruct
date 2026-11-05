// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca790();
extern int sub_b_009ca790(void*);
extern int g_b_009ca790;

void func_009ca790()
{
    sub_a_009ca790();
    sub_b_009ca790(&g_b_009ca790);
}
