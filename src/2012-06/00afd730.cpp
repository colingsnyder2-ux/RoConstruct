// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd730();
extern int sub_b_00afd730(void*);
extern int g_b_00afd730;

void func_00afd730()
{
    sub_a_00afd730();
    sub_b_00afd730(&g_b_00afd730);
}
