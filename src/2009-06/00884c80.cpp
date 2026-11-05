// from server: 100% by colin
extern int g_00884c80_0;
extern int g_00884c80_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00884c80(void*);
struct O_00884c80 { int m(void*, void*, int, int); };
extern O_00884c80 g_obj_00884c80;
extern int g_tail_00884c80;
void func_00884c80()
{
    g_obj_00884c80.m((void*)&g_00884c80_0, (void*)&g_00884c80_1, 176, 7);
    tail_fn_00884c80(&g_tail_00884c80);
}