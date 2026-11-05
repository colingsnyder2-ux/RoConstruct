// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c3810();
extern int sub_b_009c3810(void*);
extern int g_b_009c3810;

void func_009c3810()
{
    sub_a_009c3810();
    sub_b_009c3810(&g_b_009c3810);
}
