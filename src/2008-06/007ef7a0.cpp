// from server: 100% by colin
extern int g_007ef7a0_0;
extern int g_007ef7a0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007ef7a0(void*);
struct O_007ef7a0 { int m(void*, void*, int, int); };
extern O_007ef7a0 g_obj_007ef7a0;
extern int g_tail_007ef7a0;
void func_007ef7a0()
{
    g_obj_007ef7a0.m((void*)&g_007ef7a0_0, (void*)&g_007ef7a0_1, 344, 4);
    tail_fn_007ef7a0(&g_tail_007ef7a0);
}