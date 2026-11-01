// from server: 100% by colin
extern int g_00884bc0_0;
extern int g_00884bc0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00884bc0(void*);
struct O_00884bc0 { int m(void*, void*, int, int); };
extern O_00884bc0 g_obj_00884bc0;
extern int g_tail_00884bc0;
void func_00884bc0()
{
    g_obj_00884bc0.m((void*)&g_00884bc0_0, (void*)&g_00884bc0_1, 141, 7);
    tail_fn_00884bc0(&g_tail_00884bc0);
}