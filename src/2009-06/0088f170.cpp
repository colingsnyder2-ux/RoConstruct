// from server: 100% by colin
extern int g_0088f170_0;
extern int g_0088f170_1;
extern int g_0088f170_2;
extern int g_0088f170_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088f170(void*);
struct O_0088f170 { int m(void*, void*, void*, void*, int); };
extern O_0088f170 g_obj_0088f170;
extern int g_tail_0088f170;
void func_0088f170()
{
    g_obj_0088f170.m((void*)&g_0088f170_0, (void*)&g_0088f170_1, (void*)&g_0088f170_2, (void*)&g_0088f170_3, 7);
    tail_fn_0088f170(&g_tail_0088f170);
}