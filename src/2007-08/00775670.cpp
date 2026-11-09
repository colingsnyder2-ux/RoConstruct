// from server: 100% by colin
extern int g_00775670_0;
extern int g_00775670_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775670(void*);
struct O_00775670 { int m(void*, void*, int, int); };
extern O_00775670 g_obj_00775670;
extern int g_tail_00775670;
void func_00775670()
{
    g_obj_00775670.m((void*)&g_00775670_0, (void*)&g_00775670_1, 272, 5);
    tail_fn_00775670(&g_tail_00775670);
}