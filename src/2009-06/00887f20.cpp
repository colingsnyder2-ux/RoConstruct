// from server: 100% by colin
extern int g_00887f20_0;
extern int g_00887f20_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887f20(void*);
struct O_00887f20 { int m(void*, void*, int, int); };
extern O_00887f20 g_obj_00887f20;
extern int g_tail_00887f20;
void func_00887f20()
{
    g_obj_00887f20.m((void*)&g_00887f20_0, (void*)&g_00887f20_1, 141, 7);
    tail_fn_00887f20(&g_tail_00887f20);
}