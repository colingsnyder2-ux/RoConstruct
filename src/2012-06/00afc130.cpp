// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc130();
extern int sub_b_00afc130(void*);
extern int g_b_00afc130;

void func_00afc130()
{
    sub_a_00afc130();
    sub_b_00afc130(&g_b_00afc130);
}
