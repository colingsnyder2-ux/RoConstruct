// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc350();
extern int sub_b_00afc350(void*);
extern int g_b_00afc350;

void func_00afc350()
{
    sub_a_00afc350();
    sub_b_00afc350(&g_b_00afc350);
}
