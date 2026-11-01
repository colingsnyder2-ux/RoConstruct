// from server: 100% by colin
extern int g_00a1bf30_0;
extern int g_00a1bf30_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a1bf30(void*);
struct O_00a1bf30 { int m(void*, void*, int, int, int); };
extern O_00a1bf30 g_obj_00a1bf30;
extern int g_tail_00a1bf30;
void func_00a1bf30()
{
    g_obj_00a1bf30.m((void*)&g_00a1bf30_0, (void*)&g_00a1bf30_1, 160, 31, 0);
    tail_fn_00a1bf30(&g_tail_00a1bf30);
}