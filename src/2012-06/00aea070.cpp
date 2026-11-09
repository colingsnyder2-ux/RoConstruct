// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00aea070();
extern int sub_b_00aea070(void*);
extern int g_b_00aea070;

void func_00aea070()
{
    sub_a_00aea070();
    sub_b_00aea070(&g_b_00aea070);
}
