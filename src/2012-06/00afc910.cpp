// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc910();
extern int sub_b_00afc910(void*);
extern int g_b_00afc910;

void func_00afc910()
{
    sub_a_00afc910();
    sub_b_00afc910(&g_b_00afc910);
}
