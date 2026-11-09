// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca770();
extern int sub_b_009ca770(void*);
extern int g_b_009ca770;

void func_009ca770()
{
    sub_a_009ca770();
    sub_b_009ca770(&g_b_009ca770);
}
