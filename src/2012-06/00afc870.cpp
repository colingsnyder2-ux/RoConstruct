// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc870();
extern int sub_b_00afc870(void*);
extern int g_b_00afc870;

void func_00afc870()
{
    sub_a_00afc870();
    sub_b_00afc870(&g_b_00afc870);
}
