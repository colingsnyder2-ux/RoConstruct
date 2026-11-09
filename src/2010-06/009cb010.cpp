// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb010();
extern int sub_b_009cb010(void*);
extern int g_b_009cb010;

void func_009cb010()
{
    sub_a_009cb010();
    sub_b_009cb010(&g_b_009cb010);
}
