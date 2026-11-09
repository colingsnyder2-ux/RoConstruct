// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb490();
extern int sub_b_009cb490(void*);
extern int g_b_009cb490;

void func_009cb490()
{
    sub_a_009cb490();
    sub_b_009cb490(&g_b_009cb490);
}
