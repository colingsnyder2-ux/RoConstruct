// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca690();
extern int sub_b_009ca690(void*);
extern int g_b_009ca690;

void func_009ca690()
{
    sub_a_009ca690();
    sub_b_009ca690(&g_b_009ca690);
}
