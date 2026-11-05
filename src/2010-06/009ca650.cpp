// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca650();
extern int sub_b_009ca650(void*);
extern int g_b_009ca650;

void func_009ca650()
{
    sub_a_009ca650();
    sub_b_009ca650(&g_b_009ca650);
}
