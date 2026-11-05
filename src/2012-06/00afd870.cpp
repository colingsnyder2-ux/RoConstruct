// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd870();
extern int sub_b_00afd870(void*);
extern int g_b_00afd870;

void func_00afd870()
{
    sub_a_00afd870();
    sub_b_00afd870(&g_b_00afd870);
}
