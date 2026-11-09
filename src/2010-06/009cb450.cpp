// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb450();
extern int sub_b_009cb450(void*);
extern int g_b_009cb450;

void func_009cb450()
{
    sub_a_009cb450();
    sub_b_009cb450(&g_b_009cb450);
}
