// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00b0d110();
extern int sub_b_00b0d110(void*);
extern int g_b_00b0d110;

void func_00b0d110()
{
    sub_a_00b0d110();
    sub_b_00b0d110(&g_b_00b0d110);
}
