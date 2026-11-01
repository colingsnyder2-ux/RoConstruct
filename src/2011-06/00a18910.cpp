// from server: 100% by colin
extern int g_00a18910_1;
extern int g_00a18910_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a18910(void*);
struct O_00a18910 { int m(int, void*, void*, int); };
extern O_00a18910 g_obj_00a18910;
extern int g_tail_00a18910;
void func_00a18910()
{
    g_obj_00a18910.m(512, (void*)&g_00a18910_1, (void*)&g_00a18910_2, 3);
    tail_fn_00a18910(&g_tail_00a18910);
}