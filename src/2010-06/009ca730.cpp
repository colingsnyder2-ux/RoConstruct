// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca730();
extern int sub_b_009ca730(void*);
extern int g_b_009ca730;

void func_009ca730()
{
    sub_a_009ca730();
    sub_b_009ca730(&g_b_009ca730);
}
