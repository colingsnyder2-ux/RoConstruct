// from server: 100% by colin
extern int g_00a2b980_0;
extern int g_00a2b980_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2b980(void*);
struct O_00a2b980 { int m(void*, void*, int, int, int); };
extern O_00a2b980 g_obj_00a2b980;
extern int g_tail_00a2b980;
void func_00a2b980()
{
    g_obj_00a2b980.m((void*)&g_00a2b980_0, (void*)&g_00a2b980_1, 344, 31, 0);
    tail_fn_00a2b980(&g_tail_00a2b980);
}