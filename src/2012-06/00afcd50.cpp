// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afcd50();
extern int sub_b_00afcd50(void*);
extern int g_b_00afcd50;

void func_00afcd50()
{
    sub_a_00afcd50();
    sub_b_00afcd50(&g_b_00afcd50);
}
