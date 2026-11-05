// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc670();
extern int sub_b_00afc670(void*);
extern int g_b_00afc670;

void func_00afc670()
{
    sub_a_00afc670();
    sub_b_00afc670(&g_b_00afc670);
}
