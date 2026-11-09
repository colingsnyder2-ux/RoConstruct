// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009ca970();
extern int sub_b_009ca970(void*);
extern int g_b_009ca970;

void func_009ca970()
{
    sub_a_009ca970();
    sub_b_009ca970(&g_b_009ca970);
}
