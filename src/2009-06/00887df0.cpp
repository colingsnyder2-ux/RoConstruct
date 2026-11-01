// from server: 100% by colin
extern int g_00887df0_0;
extern int g_00887df0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887df0(void*);
struct O_00887df0 { int m(void*, void*, int, int); };
extern O_00887df0 g_obj_00887df0;
extern int g_tail_00887df0;
void func_00887df0()
{
    g_obj_00887df0.m((void*)&g_00887df0_0, (void*)&g_00887df0_1, 180, 7);
    tail_fn_00887df0(&g_tail_00887df0);
}