// from server: 100% by colin
extern int g_00887070_0;
extern int g_00887070_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887070(void*);
struct O_00887070 { int m(void*, void*, int, int); };
extern O_00887070 g_obj_00887070;
extern int g_tail_00887070;
void func_00887070()
{
    g_obj_00887070.m((void*)&g_00887070_0, (void*)&g_00887070_1, 196, 6);
    tail_fn_00887070(&g_tail_00887070);
}