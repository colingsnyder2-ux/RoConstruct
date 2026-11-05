// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc830();
extern int sub_b_00afc830(void*);
extern int g_b_00afc830;

void func_00afc830()
{
    sub_a_00afc830();
    sub_b_00afc830(&g_b_00afc830);
}
