// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca270();
extern int sub_b_009ca270(void*);
extern int g_b_009ca270;

void func_009ca270()
{
    sub_a_009ca270();
    sub_b_009ca270(&g_b_009ca270);
}
