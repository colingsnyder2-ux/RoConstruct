// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c7220();
extern int sub_b_009c7220(void*);
extern int g_b_009c7220;

void func_009c7220()
{
    sub_a_009c7220();
    sub_b_009c7220(&g_b_009c7220);
}
