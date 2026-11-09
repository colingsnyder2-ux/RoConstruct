// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afda30();
extern int sub_b_00afda30(void*);
extern int g_b_00afda30;

void func_00afda30()
{
    sub_a_00afda30();
    sub_b_00afda30(&g_b_00afda30);
}
