// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc950();
extern int sub_b_00afc950(void*);
extern int g_b_00afc950;

void func_00afc950()
{
    sub_a_00afc950();
    sub_b_00afc950(&g_b_00afc950);
}
