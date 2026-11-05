// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd810();
extern int sub_b_00afd810(void*);
extern int g_b_00afd810;

void func_00afd810()
{
    sub_a_00afd810();
    sub_b_00afd810(&g_b_00afd810);
}
