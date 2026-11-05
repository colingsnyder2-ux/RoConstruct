// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cad10();
extern int sub_b_009cad10(void*);
extern int g_b_009cad10;

void func_009cad10()
{
    sub_a_009cad10();
    sub_b_009cad10(&g_b_009cad10);
}
