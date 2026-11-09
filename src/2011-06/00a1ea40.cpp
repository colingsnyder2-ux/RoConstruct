// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1ea40();
extern int sub_b_00a1ea40(void*);
extern int g_b_00a1ea40;

void func_00a1ea40()
{
    sub_a_00a1ea40();
    sub_b_00a1ea40(&g_b_00a1ea40);
}
