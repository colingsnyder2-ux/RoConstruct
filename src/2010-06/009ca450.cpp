// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca450();
extern int sub_b_009ca450(void*);
extern int g_b_009ca450;

void func_009ca450()
{
    sub_a_009ca450();
    sub_b_009ca450(&g_b_009ca450);
}
