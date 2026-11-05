// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00af4780();
extern int sub_b_00af4780(void*);
extern int g_b_00af4780;

void func_00af4780()
{
    sub_a_00af4780();
    sub_b_00af4780(&g_b_00af4780);
}
