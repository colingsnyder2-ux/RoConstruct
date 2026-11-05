// from server: 100% by colin
extern int g_00775700_0;
extern int g_00775700_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775700(void*);
struct O_00775700 { int m(void*, void*, int, int); };
extern O_00775700 g_obj_00775700;
extern int g_tail_00775700;
void func_00775700()
{
    g_obj_00775700.m((void*)&g_00775700_0, (void*)&g_00775700_1, 252, 5);
    tail_fn_00775700(&g_tail_00775700);
}