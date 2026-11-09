// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009d1190();
extern int sub_b_009d1190(void*);
extern int g_b_009d1190;

void func_009d1190()
{
    sub_a_009d1190();
    sub_b_009d1190(&g_b_009d1190);
}
