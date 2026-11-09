// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc330();
extern int sub_b_00afc330(void*);
extern int g_b_00afc330;

void func_00afc330()
{
    sub_a_00afc330();
    sub_b_00afc330(&g_b_00afc330);
}
