// from server: 100% by colin
extern int g_0088f2c0_0;
extern int g_0088f2c0_1;
extern int g_0088f2c0_2;
extern int g_0088f2c0_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088f2c0(void*);
struct O_0088f2c0 { int m(void*, void*, void*, void*, int); };
extern O_0088f2c0 g_obj_0088f2c0;
extern int g_tail_0088f2c0;
void func_0088f2c0()
{
    g_obj_0088f2c0.m((void*)&g_0088f2c0_0, (void*)&g_0088f2c0_1, (void*)&g_0088f2c0_2, (void*)&g_0088f2c0_3, 7);
    tail_fn_0088f2c0(&g_tail_0088f2c0);
}