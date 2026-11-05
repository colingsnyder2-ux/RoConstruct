// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd850();
extern int sub_b_00afd850(void*);
extern int g_b_00afd850;

void func_00afd850()
{
    sub_a_00afd850();
    sub_b_00afd850(&g_b_00afd850);
}
