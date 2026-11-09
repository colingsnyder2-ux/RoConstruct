// from server: 100% by colin
extern int g_00a19730_0;
extern int g_00a19730_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a19730(void*);
struct O_00a19730 { int m(void*, void*, int, int, int); };
extern O_00a19730 g_obj_00a19730;
extern int g_tail_00a19730;
void func_00a19730()
{
    g_obj_00a19730.m((void*)&g_00a19730_0, (void*)&g_00a19730_1, 152, 31, 0);
    tail_fn_00a19730(&g_tail_00a19730);
}