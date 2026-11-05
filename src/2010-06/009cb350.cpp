// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb350();
extern int sub_b_009cb350(void*);
extern int g_b_009cb350;

void func_009cb350()
{
    sub_a_009cb350();
    sub_b_009cb350(&g_b_009cb350);
}
