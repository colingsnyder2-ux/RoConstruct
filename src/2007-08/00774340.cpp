// from server: 100% by colin
extern int g_00774340_0;
extern int g_00774340_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00774340(void*);
struct O_00774340 { int m(void*, void*, int, int); };
extern O_00774340 g_obj_00774340;
extern int g_tail_00774340;
void func_00774340()
{
    g_obj_00774340.m((void*)&g_00774340_0, (void*)&g_00774340_1, 360, 5);
    tail_fn_00774340(&g_tail_00774340);
}