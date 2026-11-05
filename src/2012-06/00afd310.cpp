// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd310();
extern int sub_b_00afd310(void*);
extern int g_b_00afd310;

void func_00afd310()
{
    sub_a_00afd310();
    sub_b_00afd310(&g_b_00afd310);
}
