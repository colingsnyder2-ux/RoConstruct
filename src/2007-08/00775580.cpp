// from server: 100% by colin
extern int g_00775580_0;
extern int g_00775580_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775580(void*);
struct O_00775580 { int m(void*, void*, int, int); };
extern O_00775580 g_obj_00775580;
extern int g_tail_00775580;
void func_00775580()
{
    g_obj_00775580.m((void*)&g_00775580_0, (void*)&g_00775580_1, 260, 5);
    tail_fn_00775580(&g_tail_00775580);
}