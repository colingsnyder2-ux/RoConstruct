// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1ce90();
extern int sub_b_00a1ce90(void*);
extern int g_b_00a1ce90;

void func_00a1ce90()
{
    sub_a_00a1ce90();
    sub_b_00a1ce90(&g_b_00a1ce90);
}
