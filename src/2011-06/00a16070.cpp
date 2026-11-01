// from server: 100% by colin
extern int g_00a16070_0;
extern int g_00a16070_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a16070(void*);
struct O_00a16070 { int m(void*, void*, int, int, int); };
extern O_00a16070 g_obj_00a16070;
extern int g_tail_00a16070;
void func_00a16070()
{
    g_obj_00a16070.m((void*)&g_00a16070_0, (void*)&g_00a16070_1, 144, 31, 0);
    tail_fn_00a16070(&g_tail_00a16070);
}