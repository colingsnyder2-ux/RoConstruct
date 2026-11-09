// from server: 100% by colin
extern int g_00775400_0;
extern int g_00775400_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775400(void*);
struct O_00775400 { int m(void*, void*, int, int); };
extern O_00775400 g_obj_00775400;
extern int g_tail_00775400;
void func_00775400()
{
    g_obj_00775400.m((void*)&g_00775400_0, (void*)&g_00775400_1, 304, 5);
    tail_fn_00775400(&g_tail_00775400);
}