// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb110();
extern int sub_b_009cb110(void*);
extern int g_b_009cb110;

void func_009cb110()
{
    sub_a_009cb110();
    sub_b_009cb110(&g_b_009cb110);
}
