// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb530();
extern int sub_b_009cb530(void*);
extern int g_b_009cb530;

void func_009cb530()
{
    sub_a_009cb530();
    sub_b_009cb530(&g_b_009cb530);
}
