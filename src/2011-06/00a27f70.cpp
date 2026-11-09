// from server: 100% by colin
extern int g_00a27f70_0;
extern int g_00a27f70_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a27f70(void*);
struct O_00a27f70 { int m(void*, void*, int, int, int); };
extern O_00a27f70 g_obj_00a27f70;
extern int g_tail_00a27f70;
void func_00a27f70()
{
    g_obj_00a27f70.m((void*)&g_00a27f70_0, (void*)&g_00a27f70_1, 152, 31, 0);
    tail_fn_00a27f70(&g_tail_00a27f70);
}