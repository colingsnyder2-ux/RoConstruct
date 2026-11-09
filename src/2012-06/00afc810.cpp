// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc810();
extern int sub_b_00afc810(void*);
extern int g_b_00afc810;

void func_00afc810()
{
    sub_a_00afc810();
    sub_b_00afc810(&g_b_00afc810);
}
