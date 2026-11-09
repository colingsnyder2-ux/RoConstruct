// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb290();
extern int sub_b_009cb290(void*);
extern int g_b_009cb290;

void func_009cb290()
{
    sub_a_009cb290();
    sub_b_009cb290(&g_b_009cb290);
}
