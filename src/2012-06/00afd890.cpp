// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd890();
extern int sub_b_00afd890(void*);
extern int g_b_00afd890;

void func_00afd890()
{
    sub_a_00afd890();
    sub_b_00afd890(&g_b_00afd890);
}
