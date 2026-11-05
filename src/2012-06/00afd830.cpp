// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd830();
extern int sub_b_00afd830(void*);
extern int g_b_00afd830;

void func_00afd830()
{
    sub_a_00afd830();
    sub_b_00afd830(&g_b_00afd830);
}
