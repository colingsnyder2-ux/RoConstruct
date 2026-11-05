// from server: 100% by colin
extern int g_008918e0_0;
extern int g_008918e0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008918e0(void*);
struct O_008918e0 { int m(void*, void*, int, int); };
extern O_008918e0 g_obj_008918e0;
extern int g_tail_008918e0;
void func_008918e0()
{
    g_obj_008918e0.m((void*)&g_008918e0_0, (void*)&g_008918e0_1, 352, 7);
    tail_fn_008918e0(&g_tail_008918e0);
}