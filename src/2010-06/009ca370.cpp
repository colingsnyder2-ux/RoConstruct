// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca370();
extern int sub_b_009ca370(void*);
extern int g_b_009ca370;

void func_009ca370()
{
    sub_a_009ca370();
    sub_b_009ca370(&g_b_009ca370);
}
