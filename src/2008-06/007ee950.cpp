// from server: 100% by colin
extern int g_007ee950_0;
extern int g_007ee950_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007ee950(void*);
struct O_007ee950 { int m(void*, void*, int, int); };
extern O_007ee950 g_obj_007ee950;
extern int g_tail_007ee950;
void func_007ee950()
{
    g_obj_007ee950.m((void*)&g_007ee950_0, (void*)&g_007ee950_1, 305, 5);
    tail_fn_007ee950(&g_tail_007ee950);
}