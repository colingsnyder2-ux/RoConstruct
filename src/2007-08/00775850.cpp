// from server: 100% by colin
extern int g_00775850_0;
extern int g_00775850_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775850(void*);
struct O_00775850 { int m(void*, void*, int, int); };
extern O_00775850 g_obj_00775850;
extern int g_tail_00775850;
void func_00775850()
{
    g_obj_00775850.m((void*)&g_00775850_0, (void*)&g_00775850_1, 264, 5);
    tail_fn_00775850(&g_tail_00775850);
}