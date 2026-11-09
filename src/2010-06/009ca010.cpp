// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca010();
extern int sub_b_009ca010(void*);
extern int g_b_009ca010;

void func_009ca010()
{
    sub_a_009ca010();
    sub_b_009ca010(&g_b_009ca010);
}
