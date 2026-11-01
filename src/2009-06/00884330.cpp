// from server: 100% by colin
extern int g_00884330_0;
extern int g_00884330_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00884330(void*);
struct O_00884330 { int m(void*, void*, int, int); };
extern O_00884330 g_obj_00884330;
extern int g_tail_00884330;
void func_00884330()
{
    g_obj_00884330.m((void*)&g_00884330_0, (void*)&g_00884330_1, 140, 7);
    tail_fn_00884330(&g_tail_00884330);
}