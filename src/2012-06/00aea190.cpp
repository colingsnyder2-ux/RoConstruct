// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00aea190();
extern int sub_b_00aea190(void*);
extern int g_b_00aea190;

void func_00aea190()
{
    sub_a_00aea190();
    sub_b_00aea190(&g_b_00aea190);
}
