// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_0088a030();
extern int sub_b_0088a030(void*);
extern int g_b_0088a030;

void func_0088a030()
{
    sub_a_0088a030();
    sub_b_0088a030(&g_b_0088a030);
}
