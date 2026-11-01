// from server: 100% by colin
extern int g_00a2c270_0;
extern int g_00a2c270_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2c270(void*);
struct O_00a2c270 { int m(void*, void*, int, int, int); };
extern O_00a2c270 g_obj_00a2c270;
extern int g_tail_00a2c270;
void func_00a2c270()
{
    g_obj_00a2c270.m((void*)&g_00a2c270_0, (void*)&g_00a2c270_1, 340, 2, 0);
    tail_fn_00a2c270(&g_tail_00a2c270);
}