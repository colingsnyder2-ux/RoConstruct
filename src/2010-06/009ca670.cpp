// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca670();
extern int sub_b_009ca670(void*);
extern int g_b_009ca670;

void func_009ca670()
{
    sub_a_009ca670();
    sub_b_009ca670(&g_b_009ca670);
}
