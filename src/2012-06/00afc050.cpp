// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc050();
extern int sub_b_00afc050(void*);
extern int g_b_00afc050;

void func_00afc050()
{
    sub_a_00afc050();
    sub_b_00afc050(&g_b_00afc050);
}
