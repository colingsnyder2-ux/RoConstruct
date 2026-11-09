// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc770();
extern int sub_b_00afc770(void*);
extern int g_b_00afc770;

void func_00afc770()
{
    sub_a_00afc770();
    sub_b_00afc770(&g_b_00afc770);
}
