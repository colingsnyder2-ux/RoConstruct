// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd970();
extern int sub_b_00afd970(void*);
extern int g_b_00afd970;

void func_00afd970()
{
    sub_a_00afd970();
    sub_b_00afd970(&g_b_00afd970);
}
