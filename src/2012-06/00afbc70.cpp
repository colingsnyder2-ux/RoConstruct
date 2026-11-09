// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afbc70();
extern int sub_b_00afbc70(void*);
extern int g_b_00afbc70;

void func_00afbc70()
{
    sub_a_00afbc70();
    sub_b_00afbc70(&g_b_00afbc70);
}
