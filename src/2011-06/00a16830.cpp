// from server: 100% by colin
extern int g_00a16830_0;
extern int g_00a16830_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a16830(void*);
struct O_00a16830 { int m(void*, void*, int, int, int); };
extern O_00a16830 g_obj_00a16830;
extern int g_tail_00a16830;
void func_00a16830()
{
    g_obj_00a16830.m((void*)&g_00a16830_0, (void*)&g_00a16830_1, 316, 31, 0);
    tail_fn_00a16830(&g_tail_00a16830);
}