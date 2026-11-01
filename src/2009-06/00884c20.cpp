// from server: 100% by colin
extern int g_00884c20_0;
extern int g_00884c20_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00884c20(void*);
struct O_00884c20 { int m(void*, void*, int, int); };
extern O_00884c20 g_obj_00884c20;
extern int g_tail_00884c20;
void func_00884c20()
{
    g_obj_00884c20.m((void*)&g_00884c20_0, (void*)&g_00884c20_1, 144, 7);
    tail_fn_00884c20(&g_tail_00884c20);
}