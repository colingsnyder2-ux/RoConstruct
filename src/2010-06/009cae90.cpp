// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cae90();
extern int sub_b_009cae90(void*);
extern int g_b_009cae90;

void func_009cae90()
{
    sub_a_009cae90();
    sub_b_009cae90(&g_b_009cae90);
}
