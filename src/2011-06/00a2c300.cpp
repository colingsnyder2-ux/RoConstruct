// from server: 100% by colin
extern int g_00a2c300_0;
extern int g_00a2c300_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2c300(void*);
struct O_00a2c300 { int m(void*, void*, int, int, int); };
extern O_00a2c300 g_obj_00a2c300;
extern int g_tail_00a2c300;
void func_00a2c300()
{
    g_obj_00a2c300.m((void*)&g_00a2c300_0, (void*)&g_00a2c300_1, 176, 31, 0);
    tail_fn_00a2c300(&g_tail_00a2c300);
}