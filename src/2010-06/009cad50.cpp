// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cad50();
extern int sub_b_009cad50(void*);
extern int g_b_009cad50;

void func_009cad50()
{
    sub_a_009cad50();
    sub_b_009cad50(&g_b_009cad50);
}
