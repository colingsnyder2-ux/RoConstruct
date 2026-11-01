// from server: 100% by colin
extern int g_00774370_0;
extern int g_00774370_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00774370(void*);
struct O_00774370 { int m(void*, void*, int, int); };
extern O_00774370 g_obj_00774370;
extern int g_tail_00774370;
void func_00774370()
{
    g_obj_00774370.m((void*)&g_00774370_0, (void*)&g_00774370_1, 392, 5);
    tail_fn_00774370(&g_tail_00774370);
}