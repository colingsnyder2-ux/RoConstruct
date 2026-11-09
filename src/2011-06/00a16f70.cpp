// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a16f70();
extern int sub_b_00a16f70(void*);
extern int g_b_00a16f70;

void func_00a16f70()
{
    sub_a_00a16f70();
    sub_b_00a16f70(&g_b_00a16f70);
}
