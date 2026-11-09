// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca510();
extern int sub_b_009ca510(void*);
extern int g_b_009ca510;

void func_009ca510()
{
    sub_a_009ca510();
    sub_b_009ca510(&g_b_009ca510);
}
