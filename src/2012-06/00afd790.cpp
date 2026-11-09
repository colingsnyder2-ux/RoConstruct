// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd790();
extern int sub_b_00afd790(void*);
extern int g_b_00afd790;

void func_00afd790()
{
    sub_a_00afd790();
    sub_b_00afd790(&g_b_00afd790);
}
