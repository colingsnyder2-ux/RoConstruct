// from server: 100% by colin
extern int g_009c64f0_1;
extern int g_009c64f0_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c64f0(void*);
struct O_009c64f0 { int m(int, void*, void*, int, int); };
extern O_009c64f0 g_obj_009c64f0;
extern int g_tail_009c64f0;
void func_009c64f0()
{
    g_obj_009c64f0.m(296, (void*)&g_009c64f0_1, (void*)&g_009c64f0_2, 0, 1);
    tail_fn_009c64f0(&g_tail_009c64f0);
}