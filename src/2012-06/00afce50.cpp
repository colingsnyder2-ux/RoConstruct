// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afce50();
extern int sub_b_00afce50(void*);
extern int g_b_00afce50;

void func_00afce50()
{
    sub_a_00afce50();
    sub_b_00afce50(&g_b_00afce50);
}
