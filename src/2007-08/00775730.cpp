// from server: 100% by colin
extern int g_00775730_0;
extern int g_00775730_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775730(void*);
struct O_00775730 { int m(void*, void*, int, int); };
extern O_00775730 g_obj_00775730;
extern int g_tail_00775730;
void func_00775730()
{
    g_obj_00775730.m((void*)&g_00775730_0, (void*)&g_00775730_1, 256, 5);
    tail_fn_00775730(&g_tail_00775730);
}