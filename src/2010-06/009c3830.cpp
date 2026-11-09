// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c3830();
extern int sub_b_009c3830(void*);
extern int g_b_009c3830;

void func_009c3830()
{
    sub_a_009c3830();
    sub_b_009c3830(&g_b_009c3830);
}
