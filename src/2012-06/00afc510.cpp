// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc510();
extern int sub_b_00afc510(void*);
extern int g_b_00afc510;

void func_00afc510()
{
    sub_a_00afc510();
    sub_b_00afc510(&g_b_00afc510);
}
