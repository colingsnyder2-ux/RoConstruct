// from server: 100% by colin
extern int g_00a2b7c0_0;
extern int g_00a2b7c0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2b7c0(void*);
struct O_00a2b7c0 { int m(void*, void*, int, int, int); };
extern O_00a2b7c0 g_obj_00a2b7c0;
extern int g_tail_00a2b7c0;
void func_00a2b7c0()
{
    g_obj_00a2b7c0.m((void*)&g_00a2b7c0_0, (void*)&g_00a2b7c0_1, 392, 31, 0);
    tail_fn_00a2b7c0(&g_tail_00a2b7c0);
}