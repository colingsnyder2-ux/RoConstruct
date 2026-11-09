// from server: 100% by colin
extern int g_00775430_0;
extern int g_00775430_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775430(void*);
struct O_00775430 { int m(void*, void*, int, int); };
extern O_00775430 g_obj_00775430;
extern int g_tail_00775430;
void func_00775430()
{
    g_obj_00775430.m((void*)&g_00775430_0, (void*)&g_00775430_1, 308, 5);
    tail_fn_00775430(&g_tail_00775430);
}