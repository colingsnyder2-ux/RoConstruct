// from server: 100% by colin
extern int g_00775460_0;
extern int g_00775460_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775460(void*);
struct O_00775460 { int m(void*, void*, int, int); };
extern O_00775460 g_obj_00775460;
extern int g_tail_00775460;
void func_00775460()
{
    g_obj_00775460.m((void*)&g_00775460_0, (void*)&g_00775460_1, 320, 5);
    tail_fn_00775460(&g_tail_00775460);
}