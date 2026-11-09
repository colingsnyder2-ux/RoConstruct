// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c7260();
extern int sub_b_009c7260(void*);
extern int g_b_009c7260;

void func_009c7260()
{
    sub_a_009c7260();
    sub_b_009c7260(&g_b_009c7260);
}
