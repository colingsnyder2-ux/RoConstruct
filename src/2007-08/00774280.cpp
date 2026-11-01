// from server: 100% by colin
extern int g_00774280_0;
extern int g_00774280_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00774280(void*);
struct O_00774280 { int m(void*, void*, int, int); };
extern O_00774280 g_obj_00774280;
extern int g_tail_00774280;
void func_00774280()
{
    g_obj_00774280.m((void*)&g_00774280_0, (void*)&g_00774280_1, 232, 5);
    tail_fn_00774280(&g_tail_00774280);
}