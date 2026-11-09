// from server: 100% by colin
extern int g_00a24360_0;
extern int g_00a24360_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a24360(void*);
struct O_00a24360 { int m(void*, void*, int, int, int); };
extern O_00a24360 g_obj_00a24360;
extern int g_tail_00a24360;
void func_00a24360()
{
    g_obj_00a24360.m((void*)&g_00a24360_0, (void*)&g_00a24360_1, 164, 31, 0);
    tail_fn_00a24360(&g_tail_00a24360);
}