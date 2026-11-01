// from server: 100% by colin
extern int g_0076d280_0;
extern int g_0076d280_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076d280(void*);
struct O_0076d280 { int m(void*, void*, int, int); };
extern O_0076d280 g_obj_0076d280;
extern int g_tail_0076d280;
void func_0076d280()
{
    g_obj_0076d280.m((void*)&g_0076d280_0, (void*)&g_0076d280_1, 248, 5);
    tail_fn_0076d280(&g_tail_0076d280);
}