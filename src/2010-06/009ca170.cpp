// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca170();
extern int sub_b_009ca170(void*);
extern int g_b_009ca170;

void func_009ca170()
{
    sub_a_009ca170();
    sub_b_009ca170(&g_b_009ca170);
}
