// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc970();
extern int sub_b_00afc970(void*);
extern int g_b_00afc970;

void func_00afc970()
{
    sub_a_00afc970();
    sub_b_00afc970(&g_b_00afc970);
}
