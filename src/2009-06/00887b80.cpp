// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00887b80();
extern int sub_b_00887b80(void*);
extern int g_b_00887b80;

void func_00887b80()
{
    sub_a_00887b80();
    sub_b_00887b80(&g_b_00887b80);
}
