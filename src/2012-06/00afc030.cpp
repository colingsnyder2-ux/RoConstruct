// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc030();
extern int sub_b_00afc030(void*);
extern int g_b_00afc030;

void func_00afc030()
{
    sub_a_00afc030();
    sub_b_00afc030(&g_b_00afc030);
}
