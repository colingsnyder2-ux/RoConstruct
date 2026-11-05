// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009cb510();
extern int sub_b_009cb510(void*);
extern int g_b_009cb510;

void func_009cb510()
{
    sub_a_009cb510();
    sub_b_009cb510(&g_b_009cb510);
}
