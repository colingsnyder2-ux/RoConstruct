// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c8430();
extern int sub_b_009c8430(void*);
extern int g_b_009c8430;

void func_009c8430()
{
    sub_a_009c8430();
    sub_b_009c8430(&g_b_009c8430);
}
