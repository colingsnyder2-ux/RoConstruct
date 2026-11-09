// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00887b20();
extern int sub_b_00887b20(void*);
extern int g_b_00887b20;

void func_00887b20()
{
    sub_a_00887b20();
    sub_b_00887b20(&g_b_00887b20);
}
