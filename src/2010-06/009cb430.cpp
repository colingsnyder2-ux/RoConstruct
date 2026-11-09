// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb430();
extern int sub_b_009cb430(void*);
extern int g_b_009cb430;

void func_009cb430()
{
    sub_a_009cb430();
    sub_b_009cb430(&g_b_009cb430);
}
