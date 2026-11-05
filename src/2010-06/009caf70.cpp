// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009caf70();
extern int sub_b_009caf70(void*);
extern int g_b_009caf70;

void func_009caf70()
{
    sub_a_009caf70();
    sub_b_009caf70(&g_b_009caf70);
}
