// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc630();
extern int sub_b_00afc630(void*);
extern int g_b_00afc630;

void func_00afc630()
{
    sub_a_00afc630();
    sub_b_00afc630(&g_b_00afc630);
}
