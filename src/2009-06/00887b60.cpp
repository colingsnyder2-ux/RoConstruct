// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00887b60();
extern int sub_b_00887b60(void*);
extern int g_b_00887b60;

void func_00887b60()
{
    sub_a_00887b60();
    sub_b_00887b60(&g_b_00887b60);
}
