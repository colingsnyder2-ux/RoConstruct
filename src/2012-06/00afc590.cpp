// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc590();
extern int sub_b_00afc590(void*);
extern int g_b_00afc590;

void func_00afc590()
{
    sub_a_00afc590();
    sub_b_00afc590(&g_b_00afc590);
}
