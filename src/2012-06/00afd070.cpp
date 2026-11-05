// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd070();
extern int sub_b_00afd070(void*);
extern int g_b_00afd070;

void func_00afd070()
{
    sub_a_00afd070();
    sub_b_00afd070(&g_b_00afd070);
}
