// from server: 100% by colin
extern int g_00884f60_0;
extern int g_00884f60_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00884f60(void*);
struct O_00884f60 { int m(void*, void*, int, int); };
extern O_00884f60 g_obj_00884f60;
extern int g_tail_00884f60;
void func_00884f60()
{
    g_obj_00884f60.m((void*)&g_00884f60_0, (void*)&g_00884f60_1, 208, 6);
    tail_fn_00884f60(&g_tail_00884f60);
}