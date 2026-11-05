// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca150();
extern int sub_b_009ca150(void*);
extern int g_b_009ca150;

void func_009ca150()
{
    sub_a_009ca150();
    sub_b_009ca150(&g_b_009ca150);
}
