// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd510();
extern int sub_b_00afd510(void*);
extern int g_b_00afd510;

void func_00afd510()
{
    sub_a_00afd510();
    sub_b_00afd510(&g_b_00afd510);
}
