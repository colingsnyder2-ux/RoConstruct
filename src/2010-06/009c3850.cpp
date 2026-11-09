// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c3850();
extern int sub_b_009c3850(void*);
extern int g_b_009c3850;

void func_009c3850()
{
    sub_a_009c3850();
    sub_b_009c3850(&g_b_009c3850);
}
