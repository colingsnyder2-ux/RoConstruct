// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb330();
extern int sub_b_009cb330(void*);
extern int g_b_009cb330;

void func_009cb330()
{
    sub_a_009cb330();
    sub_b_009cb330(&g_b_009cb330);
}
