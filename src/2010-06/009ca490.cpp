// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca490();
extern int sub_b_009ca490(void*);
extern int g_b_009ca490;

void func_009ca490()
{
    sub_a_009ca490();
    sub_b_009ca490(&g_b_009ca490);
}
