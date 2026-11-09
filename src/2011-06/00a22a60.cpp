// from server: 100% by colin
extern int g_00a22a60_0;
extern int g_00a22a60_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a22a60(void*);
struct O_00a22a60 { int m(void*, void*, int, int, int); };
extern O_00a22a60 g_obj_00a22a60;
extern int g_tail_00a22a60;
void func_00a22a60()
{
    g_obj_00a22a60.m((void*)&g_00a22a60_0, (void*)&g_00a22a60_1, 284, 21, 3);
    tail_fn_00a22a60(&g_tail_00a22a60);
}