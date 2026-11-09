// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd370();
extern int sub_b_00afd370(void*);
extern int g_b_00afd370;

void func_00afd370()
{
    sub_a_00afd370();
    sub_b_00afd370(&g_b_00afd370);
}
