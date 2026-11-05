// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd210();
extern int sub_b_00afd210(void*);
extern int g_b_00afd210;

void func_00afd210()
{
    sub_a_00afd210();
    sub_b_00afd210(&g_b_00afd210);
}
