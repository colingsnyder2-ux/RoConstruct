// from server: 100% by colin
extern int g_00a24300_0;
extern int g_00a24300_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a24300(void*);
struct O_00a24300 { int m(void*, void*, int, int, int); };
extern O_00a24300 g_obj_00a24300;
extern int g_tail_00a24300;
void func_00a24300()
{
    g_obj_00a24300.m((void*)&g_00a24300_0, (void*)&g_00a24300_1, 161, 31, 0);
    tail_fn_00a24300(&g_tail_00a24300);
}