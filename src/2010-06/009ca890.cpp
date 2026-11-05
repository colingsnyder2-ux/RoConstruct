// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca890();
extern int sub_b_009ca890(void*);
extern int g_b_009ca890;

void func_009ca890()
{
    sub_a_009ca890();
    sub_b_009ca890(&g_b_009ca890);
}
