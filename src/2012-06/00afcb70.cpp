// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afcb70();
extern int sub_b_00afcb70(void*);
extern int g_b_00afcb70;

void func_00afcb70()
{
    sub_a_00afcb70();
    sub_b_00afcb70(&g_b_00afcb70);
}
