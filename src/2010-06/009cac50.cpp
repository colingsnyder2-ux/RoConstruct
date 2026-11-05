// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cac50();
extern int sub_b_009cac50(void*);
extern int g_b_009cac50;

void func_009cac50()
{
    sub_a_009cac50();
    sub_b_009cac50(&g_b_009cac50);
}
