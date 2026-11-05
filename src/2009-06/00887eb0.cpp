// from server: 100% by colin
extern int g_00887eb0_0;
extern int g_00887eb0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887eb0(void*);
struct O_00887eb0 { int m(void*, void*, int, int); };
extern O_00887eb0 g_obj_00887eb0;
extern int g_tail_00887eb0;
void func_00887eb0()
{
    g_obj_00887eb0.m((void*)&g_00887eb0_0, (void*)&g_00887eb0_1, 200, 7);
    tail_fn_00887eb0(&g_tail_00887eb0);
}