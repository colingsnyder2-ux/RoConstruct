// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca810();
extern int sub_b_009ca810(void*);
extern int g_b_009ca810;

void func_009ca810()
{
    sub_a_009ca810();
    sub_b_009ca810(&g_b_009ca810);
}
