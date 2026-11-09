// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a16190();
extern int sub_b_00a16190(void*);
extern int g_b_00a16190;

void func_00a16190()
{
    sub_a_00a16190();
    sub_b_00a16190(&g_b_00a16190);
}
