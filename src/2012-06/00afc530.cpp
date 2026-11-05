// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc530();
extern int sub_b_00afc530(void*);
extern int g_b_00afc530;

void func_00afc530()
{
    sub_a_00afc530();
    sub_b_00afc530(&g_b_00afc530);
}
