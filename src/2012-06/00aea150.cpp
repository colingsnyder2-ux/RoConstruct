// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00aea150();
extern int sub_b_00aea150(void*);
extern int g_b_00aea150;

void func_00aea150()
{
    sub_a_00aea150();
    sub_b_00aea150(&g_b_00aea150);
}
