// from server: 100% by colin
extern int g_00a2a790_1;
extern int g_00a2a790_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2a790(void*);
struct O_00a2a790 { int m(int, void*, void*, int); };
extern O_00a2a790 g_obj_00a2a790;
extern int g_tail_00a2a790;
void func_00a2a790()
{
    g_obj_00a2a790.m(148, (void*)&g_00a2a790_1, (void*)&g_00a2a790_2, 0);
    tail_fn_00a2a790(&g_tail_00a2a790);
}