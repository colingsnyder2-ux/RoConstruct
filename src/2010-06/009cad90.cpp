// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cad90();
extern int sub_b_009cad90(void*);
extern int g_b_009cad90;

void func_009cad90()
{
    sub_a_009cad90();
    sub_b_009cad90(&g_b_009cad90);
}
