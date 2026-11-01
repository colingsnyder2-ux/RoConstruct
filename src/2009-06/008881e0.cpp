// from server: 100% by colin
extern int g_008881e0_1;
extern int g_008881e0_2;
extern int g_008881e0_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008881e0(void*);
struct O_008881e0 { int m(int, void*, void*, void*); };
extern O_008881e0 g_obj_008881e0;
extern int g_tail_008881e0;
void func_008881e0()
{
    g_obj_008881e0.m(364, (void*)&g_008881e0_1, (void*)&g_008881e0_2, (void*)&g_008881e0_3);
    tail_fn_008881e0(&g_tail_008881e0);
}