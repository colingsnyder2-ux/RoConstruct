// from server: 100% by colin
extern int g_00a18880_1;
extern int g_00a18880_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a18880(void*);
struct O_00a18880 { int m(int, void*, void*, int); };
extern O_00a18880 g_obj_00a18880;
extern int g_tail_00a18880;
void func_00a18880()
{
    g_obj_00a18880.m(500, (void*)&g_00a18880_1, (void*)&g_00a18880_2, 3);
    tail_fn_00a18880(&g_tail_00a18880);
}