// from server: 100% by colin
extern int g_00884f00_0;
extern int g_00884f00_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00884f00(void*);
struct O_00884f00 { int m(void*, void*, int, int); };
extern O_00884f00 g_obj_00884f00;
extern int g_tail_00884f00;
void func_00884f00()
{
    g_obj_00884f00.m((void*)&g_00884f00_0, (void*)&g_00884f00_1, 264, 7);
    tail_fn_00884f00(&g_tail_00884f00);
}