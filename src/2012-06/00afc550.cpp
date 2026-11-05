// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc550();
extern int sub_b_00afc550(void*);
extern int g_b_00afc550;

void func_00afc550()
{
    sub_a_00afc550();
    sub_b_00afc550(&g_b_00afc550);
}
