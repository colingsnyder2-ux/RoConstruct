// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc230();
extern int sub_b_00afc230(void*);
extern int g_b_00afc230;

void func_00afc230()
{
    sub_a_00afc230();
    sub_b_00afc230(&g_b_00afc230);
}
