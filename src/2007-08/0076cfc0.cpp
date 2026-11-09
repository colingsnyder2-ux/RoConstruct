// from server: 100% by colin
extern int g_0076cfc0_0;
extern int g_0076cfc0_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076cfc0(void*);
struct O_0076cfc0 { int m(void*, void*, int, int); };
extern O_0076cfc0 g_obj_0076cfc0;
extern int g_tail_0076cfc0;
void func_0076cfc0()
{
    g_obj_0076cfc0.m((void*)&g_0076cfc0_0, (void*)&g_0076cfc0_1, 264, 5);
    tail_fn_0076cfc0(&g_tail_0076cfc0);
}