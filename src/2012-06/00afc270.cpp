// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afc270();
extern int sub_b_00afc270(void*);
extern int g_b_00afc270;

void func_00afc270()
{
    sub_a_00afc270();
    sub_b_00afc270(&g_b_00afc270);
}
