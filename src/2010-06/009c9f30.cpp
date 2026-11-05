// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c9f30();
extern int sub_b_009c9f30(void*);
extern int g_b_009c9f30;

void func_009c9f30()
{
    sub_a_009c9f30();
    sub_b_009c9f30(&g_b_009c9f30);
}
