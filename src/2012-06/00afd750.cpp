// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd750();
extern int sub_b_00afd750(void*);
extern int g_b_00afd750;

void func_00afd750()
{
    sub_a_00afd750();
    sub_b_00afd750(&g_b_00afd750);
}
