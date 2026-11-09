// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca090();
extern int sub_b_009ca090(void*);
extern int g_b_009ca090;

void func_009ca090()
{
    sub_a_009ca090();
    sub_b_009ca090(&g_b_009ca090);
}
