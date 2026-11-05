// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afbe70();
extern int sub_b_00afbe70(void*);
extern int g_b_00afbe70;

void func_00afbe70()
{
    sub_a_00afbe70();
    sub_b_00afbe70(&g_b_00afbe70);
}
