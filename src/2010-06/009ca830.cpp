// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca830();
extern int sub_b_009ca830(void*);
extern int g_b_009ca830;

void func_009ca830()
{
    sub_a_009ca830();
    sub_b_009ca830(&g_b_009ca830);
}
