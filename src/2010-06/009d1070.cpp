// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009d1070();
extern int sub_b_009d1070(void*);
extern int g_b_009d1070;

void func_009d1070()
{
    sub_a_009d1070();
    sub_b_009d1070(&g_b_009d1070);
}
