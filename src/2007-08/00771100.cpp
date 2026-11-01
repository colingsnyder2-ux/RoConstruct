// from server: 100% by colin
extern int g_00771100_0;
extern int g_00771100_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00771100(void*);
struct O_00771100 { int m(void*, void*, int, int); };
extern O_00771100 g_obj_00771100;
extern int g_tail_00771100;
void func_00771100()
{
    g_obj_00771100.m((void*)&g_00771100_0, (void*)&g_00771100_1, 241, 5);
    tail_fn_00771100(&g_tail_00771100);
}