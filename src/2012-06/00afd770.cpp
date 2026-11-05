// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd770();
extern int sub_b_00afd770(void*);
extern int g_b_00afd770;

void func_00afd770()
{
    sub_a_00afd770();
    sub_b_00afd770(&g_b_00afd770);
}
