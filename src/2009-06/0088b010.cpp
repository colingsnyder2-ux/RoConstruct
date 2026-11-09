// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_0088b010();
extern int sub_b_0088b010(void*);
extern int g_b_0088b010;

void func_0088b010()
{
    sub_a_0088b010();
    sub_b_0088b010(&g_b_0088b010);
}
