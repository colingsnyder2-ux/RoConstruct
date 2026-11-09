// from server: 100% by colin
extern int g_00774310_0;
extern int g_00774310_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00774310(void*);
struct O_00774310 { int m(void*, void*, int, int); };
extern O_00774310 g_obj_00774310;
extern int g_tail_00774310;
void func_00774310()
{
    g_obj_00774310.m((void*)&g_00774310_0, (void*)&g_00774310_1, 328, 5);
    tail_fn_00774310(&g_tail_00774310);
}