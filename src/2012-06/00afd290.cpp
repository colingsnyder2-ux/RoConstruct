// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd290();
extern int sub_b_00afd290(void*);
extern int g_b_00afd290;

void func_00afd290()
{
    sub_a_00afd290();
    sub_b_00afd290(&g_b_00afd290);
}
