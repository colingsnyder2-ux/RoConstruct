// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb550();
extern int sub_b_009cb550(void*);
extern int g_b_009cb550;

void func_009cb550()
{
    sub_a_009cb550();
    sub_b_009cb550(&g_b_009cb550);
}
