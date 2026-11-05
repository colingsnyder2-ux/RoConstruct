// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca910();
extern int sub_b_009ca910(void*);
extern int g_b_009ca910;

void func_009ca910()
{
    sub_a_009ca910();
    sub_b_009ca910(&g_b_009ca910);
}
