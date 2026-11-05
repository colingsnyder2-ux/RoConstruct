// from server: 100% by colin
extern int g_00773560_0;
extern int g_00773560_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00773560(void*);
struct O_00773560 { int m(void*, void*, int, int); };
extern O_00773560 g_obj_00773560;
extern int g_tail_00773560;
void func_00773560()
{
    g_obj_00773560.m((void*)&g_00773560_0, (void*)&g_00773560_1, 236, 5);
    tail_fn_00773560(&g_tail_00773560);
}