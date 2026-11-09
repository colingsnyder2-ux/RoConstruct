// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c7280();
extern int sub_b_009c7280(void*);
extern int g_b_009c7280;

void func_009c7280()
{
    sub_a_009c7280();
    sub_b_009c7280(&g_b_009c7280);
}
