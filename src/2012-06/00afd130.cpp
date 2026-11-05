// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd130();
extern int sub_b_00afd130(void*);
extern int g_b_00afd130;

void func_00afd130()
{
    sub_a_00afd130();
    sub_b_00afd130(&g_b_00afd130);
}
