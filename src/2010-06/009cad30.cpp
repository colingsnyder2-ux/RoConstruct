// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cad30();
extern int sub_b_009cad30(void*);
extern int g_b_009cad30;

void func_009cad30()
{
    sub_a_009cad30();
    sub_b_009cad30(&g_b_009cad30);
}
