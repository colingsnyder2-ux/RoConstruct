// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd670();
extern int sub_b_00afd670(void*);
extern int g_b_00afd670;

void func_00afd670()
{
    sub_a_00afd670();
    sub_b_00afd670(&g_b_00afd670);
}
