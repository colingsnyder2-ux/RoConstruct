// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_009c9f70();
extern int sub_b_009c9f70(void*);
extern int g_b_009c9f70;

void func_009c9f70()
{
    sub_a_009c9f70();
    sub_b_009c9f70(&g_b_009c9f70);
}
