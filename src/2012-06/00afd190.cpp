// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd190();
extern int sub_b_00afd190(void*);
extern int g_b_00afd190;

void func_00afd190()
{
    sub_a_00afd190();
    sub_b_00afd190(&g_b_00afd190);
}
