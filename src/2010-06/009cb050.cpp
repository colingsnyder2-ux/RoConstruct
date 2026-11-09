// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb050();
extern int sub_b_009cb050(void*);
extern int g_b_009cb050;

void func_009cb050()
{
    sub_a_009cb050();
    sub_b_009cb050(&g_b_009cb050);
}
