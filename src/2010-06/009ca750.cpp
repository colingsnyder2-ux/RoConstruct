// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca750();
extern int sub_b_009ca750(void*);
extern int g_b_009ca750;

void func_009ca750()
{
    sub_a_009ca750();
    sub_b_009ca750(&g_b_009ca750);
}
