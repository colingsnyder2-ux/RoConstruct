// from server: 100% by colin
extern int g_00775310_0;
extern int g_00775310_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775310(void*);
struct O_00775310 { int m(void*, void*, int, int); };
extern O_00775310 g_obj_00775310;
extern int g_tail_00775310;
void func_00775310()
{
    g_obj_00775310.m((void*)&g_00775310_0, (void*)&g_00775310_1, 296, 5);
    tail_fn_00775310(&g_tail_00775310);
}