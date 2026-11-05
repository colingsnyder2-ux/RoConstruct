// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc150();
extern int sub_b_00afc150(void*);
extern int g_b_00afc150;

void func_00afc150()
{
    sub_a_00afc150();
    sub_b_00afc150(&g_b_00afc150);
}
