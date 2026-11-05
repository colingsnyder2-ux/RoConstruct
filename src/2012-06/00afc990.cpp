// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc990();
extern int sub_b_00afc990(void*);
extern int g_b_00afc990;

void func_00afc990()
{
    sub_a_00afc990();
    sub_b_00afc990(&g_b_00afc990);
}
