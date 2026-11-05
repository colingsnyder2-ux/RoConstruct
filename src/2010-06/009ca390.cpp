// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca390();
extern int sub_b_009ca390(void*);
extern int g_b_009ca390;

void func_009ca390()
{
    sub_a_009ca390();
    sub_b_009ca390(&g_b_009ca390);
}
