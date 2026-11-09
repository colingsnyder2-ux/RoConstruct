// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009caa70();
extern int sub_b_009caa70(void*);
extern int g_b_009caa70;

void func_009caa70()
{
    sub_a_009caa70();
    sub_b_009caa70(&g_b_009caa70);
}
