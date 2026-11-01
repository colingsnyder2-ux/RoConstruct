// from server: 100% by colin
extern int g_00889fb0_0;
extern int g_00889fb0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00889fb0(void*);
struct O_00889fb0 { int m(void*, void*, int, int); };
extern O_00889fb0 g_obj_00889fb0;
extern int g_tail_00889fb0;
void func_00889fb0()
{
    g_obj_00889fb0.m((void*)&g_00889fb0_0, (void*)&g_00889fb0_1, 149, 7);
    tail_fn_00889fb0(&g_tail_00889fb0);
}