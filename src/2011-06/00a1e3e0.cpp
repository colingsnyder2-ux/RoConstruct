// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1e3e0();
extern int sub_b_00a1e3e0(void*);
extern int g_b_00a1e3e0;

void func_00a1e3e0()
{
    sub_a_00a1e3e0();
    sub_b_00a1e3e0(&g_b_00a1e3e0);
}
