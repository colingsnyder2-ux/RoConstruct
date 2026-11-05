// from server: 100% by colin
extern int g_00a1c850_1;
extern int g_00a1c850_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a1c850(void*);
struct O_00a1c850 { int m(int, void*, void*, int); };
extern O_00a1c850 g_obj_00a1c850;
extern int g_tail_00a1c850;
void func_00a1c850()
{
    g_obj_00a1c850.m(120, (void*)&g_00a1c850_1, (void*)&g_00a1c850_2, 0);
    tail_fn_00a1c850(&g_tail_00a1c850);
}