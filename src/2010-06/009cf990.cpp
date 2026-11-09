// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cf990();
extern int sub_b_009cf990(void*);
extern int g_b_009cf990;

void func_009cf990()
{
    sub_a_009cf990();
    sub_b_009cf990(&g_b_009cf990);
}
