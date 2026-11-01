// from server: 100% by colin
extern int g_007ef3d0_0;
extern int g_007ef3d0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007ef3d0(void*);
struct O_007ef3d0 { int m(void*, void*, int, int); };
extern O_007ef3d0 g_obj_007ef3d0;
extern int g_tail_007ef3d0;
void func_007ef3d0()
{
    g_obj_007ef3d0.m((void*)&g_007ef3d0_0, (void*)&g_007ef3d0_1, 336, 5);
    tail_fn_007ef3d0(&g_tail_007ef3d0);
}