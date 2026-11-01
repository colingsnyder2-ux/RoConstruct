// from server: 100% by colin
extern int g_00775760_0;
extern int g_00775760_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775760(void*);
struct O_00775760 { int m(void*, void*, int, int); };
extern O_00775760 g_obj_00775760;
extern int g_tail_00775760;
void func_00775760()
{
    g_obj_00775760.m((void*)&g_00775760_0, (void*)&g_00775760_1, 268, 5);
    tail_fn_00775760(&g_tail_00775760);
}