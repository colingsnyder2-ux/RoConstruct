// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb130();
extern int sub_b_009cb130(void*);
extern int g_b_009cb130;

void func_009cb130()
{
    sub_a_009cb130();
    sub_b_009cb130(&g_b_009cb130);
}
