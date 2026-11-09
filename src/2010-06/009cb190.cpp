// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb190();
extern int sub_b_009cb190(void*);
extern int g_b_009cb190;

void func_009cb190()
{
    sub_a_009cb190();
    sub_b_009cb190(&g_b_009cb190);
}
