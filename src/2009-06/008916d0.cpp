// from server: 100% by colin
extern int g_008916d0_0;
extern int g_008916d0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008916d0(void*);
struct O_008916d0 { int m(void*, void*, int, int); };
extern O_008916d0 g_obj_008916d0;
extern int g_tail_008916d0;
void func_008916d0()
{
    g_obj_008916d0.m((void*)&g_008916d0_0, (void*)&g_008916d0_1, 344, 7);
    tail_fn_008916d0(&g_tail_008916d0);
}