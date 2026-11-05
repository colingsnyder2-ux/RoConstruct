// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a1f200();
extern int sub_b_00a1f200(void*);
extern int g_b_00a1f200;

void func_00a1f200()
{
    sub_a_00a1f200();
    sub_b_00a1f200(&g_b_00a1f200);
}
