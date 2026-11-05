// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca710();
extern int sub_b_009ca710(void*);
extern int g_b_009ca710;

void func_009ca710()
{
    sub_a_009ca710();
    sub_b_009ca710(&g_b_009ca710);
}
