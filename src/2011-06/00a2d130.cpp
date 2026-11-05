// from server: 100% by colin
extern int g_00a2d130_0;
extern int g_00a2d130_1;
extern int g_00a2d130_2;
extern int g_00a2d130_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2d130(void*);
struct O_00a2d130 { int m(void*, void*, void*, void*, int); };
extern O_00a2d130 g_obj_00a2d130;
extern int g_tail_00a2d130;
void func_00a2d130()
{
    g_obj_00a2d130.m((void*)&g_00a2d130_0, (void*)&g_00a2d130_1, (void*)&g_00a2d130_2, (void*)&g_00a2d130_3, 31);
    tail_fn_00a2d130(&g_tail_00a2d130);
}