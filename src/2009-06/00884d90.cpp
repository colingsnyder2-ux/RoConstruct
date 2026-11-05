// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00884d90();
extern int sub_b_00884d90(void*);
extern int g_b_00884d90;

void func_00884d90()
{
    sub_a_00884d90();
    sub_b_00884d90(&g_b_00884d90);
}
