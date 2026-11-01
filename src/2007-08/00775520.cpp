// from server: 100% by colin
extern int g_00775520_0;
extern int g_00775520_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775520(void*);
struct O_00775520 { int m(void*, void*, int, int); };
extern O_00775520 g_obj_00775520;
extern int g_tail_00775520;
void func_00775520()
{
    g_obj_00775520.m((void*)&g_00775520_0, (void*)&g_00775520_1, 252, 5);
    tail_fn_00775520(&g_tail_00775520);
}