// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd490();
extern int sub_b_00afd490(void*);
extern int g_b_00afd490;

void func_00afd490()
{
    sub_a_00afd490();
    sub_b_00afd490(&g_b_00afd490);
}
