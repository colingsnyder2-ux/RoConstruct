// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca930();
extern int sub_b_009ca930(void*);
extern int g_b_009ca930;

void func_009ca930()
{
    sub_a_009ca930();
    sub_b_009ca930(&g_b_009ca930);
}
