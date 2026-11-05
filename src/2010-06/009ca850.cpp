// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca850();
extern int sub_b_009ca850(void*);
extern int g_b_009ca850;

void func_009ca850()
{
    sub_a_009ca850();
    sub_b_009ca850(&g_b_009ca850);
}
