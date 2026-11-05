// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00af7eb0();
extern int sub_b_00af7eb0(void*);
extern int g_b_00af7eb0;

void func_00af7eb0()
{
    sub_a_00af7eb0();
    sub_b_00af7eb0(&g_b_00af7eb0);
}
