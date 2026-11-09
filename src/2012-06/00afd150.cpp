// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_00afd150();
extern int sub_b_00afd150(void*);
extern int g_b_00afd150;

void func_00afd150()
{
    sub_a_00afd150();
    sub_b_00afd150(&g_b_00afd150);
}
