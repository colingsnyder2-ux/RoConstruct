// from server: 100% by colin
extern int g_009c90c0_0;
extern int g_009c90c0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c90c0(void*);
struct O_009c90c0 { int m(void*, void*, int, int, int); };
extern O_009c90c0 g_obj_009c90c0;
extern int g_tail_009c90c0;
void func_009c90c0()
{
    g_obj_009c90c0.m((void*)&g_009c90c0_0, (void*)&g_009c90c0_1, 165, 15, 0);
    tail_fn_009c90c0(&g_tail_009c90c0);
}