// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd990();
extern int sub_b_00afd990(void*);
extern int g_b_00afd990;

void func_00afd990()
{
    sub_a_00afd990();
    sub_b_00afd990(&g_b_00afd990);
}
