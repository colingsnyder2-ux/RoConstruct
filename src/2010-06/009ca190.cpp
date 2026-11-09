// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca190();
extern int sub_b_009ca190(void*);
extern int g_b_009ca190;

void func_009ca190()
{
    sub_a_009ca190();
    sub_b_009ca190(&g_b_009ca190);
}
