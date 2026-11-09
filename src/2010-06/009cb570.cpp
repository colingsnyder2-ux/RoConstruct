// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb570();
extern int sub_b_009cb570(void*);
extern int g_b_009cb570;

void func_009cb570()
{
    sub_a_009cb570();
    sub_b_009cb570(&g_b_009cb570);
}
