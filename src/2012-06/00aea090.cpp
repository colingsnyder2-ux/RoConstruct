// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00aea090();
extern int sub_b_00aea090(void*);
extern int g_b_00aea090;

void func_00aea090()
{
    sub_a_00aea090();
    sub_b_00aea090(&g_b_00aea090);
}
