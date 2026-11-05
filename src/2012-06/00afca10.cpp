// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afca10();
extern int sub_b_00afca10(void*);
extern int g_b_00afca10;

void func_00afca10()
{
    sub_a_00afca10();
    sub_b_00afca10(&g_b_00afca10);
}
