// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00b0d150();
extern int sub_b_00b0d150(void*);
extern int g_b_00b0d150;

void func_00b0d150()
{
    sub_a_00b0d150();
    sub_b_00b0d150(&g_b_00b0d150);
}
