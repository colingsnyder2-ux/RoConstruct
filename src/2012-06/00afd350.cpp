// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd350();
extern int sub_b_00afd350(void*);
extern int g_b_00afd350;

void func_00afd350()
{
    sub_a_00afd350();
    sub_b_00afd350(&g_b_00afd350);
}
