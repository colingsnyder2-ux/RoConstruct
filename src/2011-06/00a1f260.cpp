// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1f260();
extern int sub_b_00a1f260(void*);
extern int g_b_00a1f260;

void func_00a1f260()
{
    sub_a_00a1f260();
    sub_b_00a1f260(&g_b_00a1f260);
}
