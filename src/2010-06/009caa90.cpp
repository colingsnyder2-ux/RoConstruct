// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009caa90();
extern int sub_b_009caa90(void*);
extern int g_b_009caa90;

void func_009caa90()
{
    sub_a_009caa90();
    sub_b_009caa90(&g_b_009caa90);
}
