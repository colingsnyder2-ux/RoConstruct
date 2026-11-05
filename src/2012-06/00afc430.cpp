// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc430();
extern int sub_b_00afc430(void*);
extern int g_b_00afc430;

void func_00afc430()
{
    sub_a_00afc430();
    sub_b_00afc430(&g_b_00afc430);
}
