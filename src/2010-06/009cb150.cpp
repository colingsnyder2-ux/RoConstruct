// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb150();
extern int sub_b_009cb150(void*);
extern int g_b_009cb150;

void func_009cb150()
{
    sub_a_009cb150();
    sub_b_009cb150(&g_b_009cb150);
}
