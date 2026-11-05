// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc570();
extern int sub_b_00afc570(void*);
extern int g_b_00afc570;

void func_00afc570()
{
    sub_a_00afc570();
    sub_b_00afc570(&g_b_00afc570);
}
