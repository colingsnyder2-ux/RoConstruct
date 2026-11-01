// from server: 100% by colin
extern int g_008913f0_0;
extern int g_008913f0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008913f0(void*);
struct O_008913f0 { int m(void*, void*, int, int); };
extern O_008913f0 g_obj_008913f0;
extern int g_tail_008913f0;
void func_008913f0()
{
    g_obj_008913f0.m((void*)&g_008913f0_0, (void*)&g_008913f0_1, 384, 7);
    tail_fn_008913f0(&g_tail_008913f0);
}