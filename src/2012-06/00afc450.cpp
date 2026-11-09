// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc450();
extern int sub_b_00afc450(void*);
extern int g_b_00afc450;

void func_00afc450()
{
    sub_a_00afc450();
    sub_b_00afc450(&g_b_00afc450);
}
