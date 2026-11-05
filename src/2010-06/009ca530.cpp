// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca530();
extern int sub_b_009ca530(void*);
extern int g_b_009ca530;

void func_009ca530()
{
    sub_a_009ca530();
    sub_b_009ca530(&g_b_009ca530);
}
