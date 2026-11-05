// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca550();
extern int sub_b_009ca550(void*);
extern int g_b_009ca550;

void func_009ca550()
{
    sub_a_009ca550();
    sub_b_009ca550(&g_b_009ca550);
}
