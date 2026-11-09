// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c7320();
extern int sub_b_009c7320(void*);
extern int g_b_009c7320;

void func_009c7320()
{
    sub_a_009c7320();
    sub_b_009c7320(&g_b_009c7320);
}
