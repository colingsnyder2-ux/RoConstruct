// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009d1090();
extern int sub_b_009d1090(void*);
extern int g_b_009d1090;

void func_009d1090()
{
    sub_a_009d1090();
    sub_b_009d1090(&g_b_009d1090);
}
