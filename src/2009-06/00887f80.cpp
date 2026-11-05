// from server: 100% by colin
extern int g_00887f80_0;
extern int g_00887f80_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887f80(void*);
struct O_00887f80 { int m(void*, void*, int, int); };
extern O_00887f80 g_obj_00887f80;
extern int g_tail_00887f80;
void func_00887f80()
{
    g_obj_00887f80.m((void*)&g_00887f80_0, (void*)&g_00887f80_1, 140, 7);
    tail_fn_00887f80(&g_tail_00887f80);
}