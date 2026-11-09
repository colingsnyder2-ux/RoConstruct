// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc650();
extern int sub_b_00afc650(void*);
extern int g_b_00afc650;

void func_00afc650()
{
    sub_a_00afc650();
    sub_b_00afc650(&g_b_00afc650);
}
