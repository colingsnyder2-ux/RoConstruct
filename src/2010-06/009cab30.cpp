// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cab30();
extern int sub_b_009cab30(void*);
extern int g_b_009cab30;

void func_009cab30()
{
    sub_a_009cab30();
    sub_b_009cab30(&g_b_009cab30);
}
