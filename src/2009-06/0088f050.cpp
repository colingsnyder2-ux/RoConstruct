// from server: 100% by colin
extern int g_0088f050_0;
extern int g_0088f050_1;
extern int g_0088f050_2;
extern int g_0088f050_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088f050(void*);
struct O_0088f050 { int m(void*, void*, void*, void*, int); };
extern O_0088f050 g_obj_0088f050;
extern int g_tail_0088f050;
void func_0088f050()
{
    g_obj_0088f050.m((void*)&g_0088f050_0, (void*)&g_0088f050_1, (void*)&g_0088f050_2, (void*)&g_0088f050_3, 7);
    tail_fn_0088f050(&g_tail_0088f050);
}