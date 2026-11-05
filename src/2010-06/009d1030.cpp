// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009d1030();
extern int sub_b_009d1030(void*);
extern int g_b_009d1030;

void func_009d1030()
{
    sub_a_009d1030();
    sub_b_009d1030(&g_b_009d1030);
}
