// from server: 100% by colin
extern int g_007f5560_0;
extern int g_007f5560_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f5560(void*);
struct O_007f5560 { int m(void*, void*, int, int); };
extern O_007f5560 g_obj_007f5560;
extern int g_tail_007f5560;
void func_007f5560()
{
    g_obj_007f5560.m((void*)&g_007f5560_0, (void*)&g_007f5560_1, 314, 5);
    tail_fn_007f5560(&g_tail_007f5560);
}