// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afda70();
extern int sub_b_00afda70(void*);
extern int g_b_00afda70;

void func_00afda70()
{
    sub_a_00afda70();
    sub_b_00afda70(&g_b_00afda70);
}
