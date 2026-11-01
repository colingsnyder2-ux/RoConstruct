// from server: 100% by colin
extern int g_00a24d40_0;
extern int g_00a24d40_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a24d40(void*);
struct O_00a24d40 { int m(void*, void*, int, int, int); };
extern O_00a24d40 g_obj_00a24d40;
extern int g_tail_00a24d40;
void func_00a24d40()
{
    g_obj_00a24d40.m((void*)&g_00a24d40_0, (void*)&g_00a24d40_1, 176, 31, 0);
    tail_fn_00a24d40(&g_tail_00a24d40);
}