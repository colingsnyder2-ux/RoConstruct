// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00a16250();
extern int sub_b_00a16250(void*);
extern int g_b_00a16250;

void func_00a16250()
{
    sub_a_00a16250();
    sub_b_00a16250(&g_b_00a16250);
}
