// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00887bc0();
extern int sub_b_00887bc0(void*);
extern int g_b_00887bc0;

void func_00887bc0()
{
    sub_a_00887bc0();
    sub_b_00887bc0(&g_b_00887bc0);
}
