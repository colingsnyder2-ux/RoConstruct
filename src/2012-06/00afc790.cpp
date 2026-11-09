// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc790();
extern int sub_b_00afc790(void*);
extern int g_b_00afc790;

void func_00afc790()
{
    sub_a_00afc790();
    sub_b_00afc790(&g_b_00afc790);
}
