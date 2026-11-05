// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb230();
extern int sub_b_009cb230(void*);
extern int g_b_009cb230;

void func_009cb230()
{
    sub_a_009cb230();
    sub_b_009cb230(&g_b_009cb230);
}
