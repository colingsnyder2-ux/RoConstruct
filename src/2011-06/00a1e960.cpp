// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1e960();
extern int sub_b_00a1e960(void*);
extern int g_b_00a1e960;

void func_00a1e960()
{
    sub_a_00a1e960();
    sub_b_00a1e960(&g_b_00a1e960);
}
