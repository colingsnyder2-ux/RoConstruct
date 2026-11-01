// from server: 100% by colin
extern int g_00a2c360_0;
extern int g_00a2c360_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2c360(void*);
struct O_00a2c360 { int m(void*, void*, int, int, int); };
extern O_00a2c360 g_obj_00a2c360;
extern int g_tail_00a2c360;
void func_00a2c360()
{
    g_obj_00a2c360.m((void*)&g_00a2c360_0, (void*)&g_00a2c360_1, 240, 31, 0);
    tail_fn_00a2c360(&g_tail_00a2c360);
}