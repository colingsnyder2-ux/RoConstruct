// from server: 100% by colin
extern int g_00884c50_0;
extern int g_00884c50_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00884c50(void*);
struct O_00884c50 { int m(void*, void*, int, int); };
extern O_00884c50 g_obj_00884c50;
extern int g_tail_00884c50;
void func_00884c50()
{
    g_obj_00884c50.m((void*)&g_00884c50_0, (void*)&g_00884c50_1, 172, 7);
    tail_fn_00884c50(&g_tail_00884c50);
}