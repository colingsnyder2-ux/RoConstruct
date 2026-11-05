// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00aea110();
extern int sub_b_00aea110(void*);
extern int g_b_00aea110;

void func_00aea110()
{
    sub_a_00aea110();
    sub_b_00aea110(&g_b_00aea110);
}
