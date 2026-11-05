// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd090();
extern int sub_b_00afd090(void*);
extern int g_b_00afd090;

void func_00afd090()
{
    sub_a_00afd090();
    sub_b_00afd090(&g_b_00afd090);
}
