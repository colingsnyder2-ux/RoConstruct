// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd650();
extern int sub_b_00afd650(void*);
extern int g_b_00afd650;

void func_00afd650()
{
    sub_a_00afd650();
    sub_b_00afd650(&g_b_00afd650);
}
