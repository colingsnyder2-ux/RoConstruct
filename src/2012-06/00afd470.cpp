// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd470();
extern int sub_b_00afd470(void*);
extern int g_b_00afd470;

void func_00afd470()
{
    sub_a_00afd470();
    sub_b_00afd470(&g_b_00afd470);
}
