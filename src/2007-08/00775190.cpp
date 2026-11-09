// from server: 100% by colin
extern int g_00775190_0;
extern int g_00775190_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775190(void*);
struct O_00775190 { int m(void*, void*, int, int); };
extern O_00775190 g_obj_00775190;
extern int g_tail_00775190;
void func_00775190()
{
    g_obj_00775190.m((void*)&g_00775190_0, (void*)&g_00775190_1, 256, 5);
    tail_fn_00775190(&g_tail_00775190);
}