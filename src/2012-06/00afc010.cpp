// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc010();
extern int sub_b_00afc010(void*);
extern int g_b_00afc010;

void func_00afc010()
{
    sub_a_00afc010();
    sub_b_00afc010(&g_b_00afc010);
}
