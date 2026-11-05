// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_0088a910();
extern int sub_b_0088a910(void*);
extern int g_b_0088a910;

void func_0088a910()
{
    sub_a_0088a910();
    sub_b_0088a910(&g_b_0088a910);
}
