// from server: 100% by colin
extern int g_00887f50_0;
extern int g_00887f50_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887f50(void*);
struct O_00887f50 { int m(void*, void*, int, int); };
extern O_00887f50 g_obj_00887f50;
extern int g_tail_00887f50;
void func_00887f50()
{
    g_obj_00887f50.m((void*)&g_00887f50_0, (void*)&g_00887f50_1, 142, 7);
    tail_fn_00887f50(&g_tail_00887f50);
}