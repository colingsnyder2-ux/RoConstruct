// from server: 100% by colin
extern int g_00773530_0;
extern int g_00773530_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00773530(void*);
struct O_00773530 { int m(void*, void*, int, int); };
extern O_00773530 g_obj_00773530;
extern int g_tail_00773530;
void func_00773530()
{
    g_obj_00773530.m((void*)&g_00773530_0, (void*)&g_00773530_1, 232, 5);
    tail_fn_00773530(&g_tail_00773530);
}