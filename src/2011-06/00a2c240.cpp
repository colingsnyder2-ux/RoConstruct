// from server: 100% by colin
extern int g_00a2c240_0;
extern int g_00a2c240_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2c240(void*);
struct O_00a2c240 { int m(void*, void*, int, int, int); };
extern O_00a2c240 g_obj_00a2c240;
extern int g_tail_00a2c240;
void func_00a2c240()
{
    g_obj_00a2c240.m((void*)&g_00a2c240_0, (void*)&g_00a2c240_1, 308, 2, 0);
    tail_fn_00a2c240(&g_tail_00a2c240);
}