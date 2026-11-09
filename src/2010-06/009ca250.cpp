// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca250();
extern int sub_b_009ca250(void*);
extern int g_b_009ca250;

void func_009ca250()
{
    sub_a_009ca250();
    sub_b_009ca250(&g_b_009ca250);
}
