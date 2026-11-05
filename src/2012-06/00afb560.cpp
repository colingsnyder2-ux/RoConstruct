// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afb560();
extern int sub_b_00afb560(void*);
extern int g_b_00afb560;

void func_00afb560()
{
    sub_a_00afb560();
    sub_b_00afb560(&g_b_00afb560);
}
