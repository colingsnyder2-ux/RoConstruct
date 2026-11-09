// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cae50();
extern int sub_b_009cae50(void*);
extern int g_b_009cae50;

void func_009cae50()
{
    sub_a_009cae50();
    sub_b_009cae50(&g_b_009cae50);
}
