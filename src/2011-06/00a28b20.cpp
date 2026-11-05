// from server: 100% by colin
extern int g_00a28b20_0;
extern int g_00a28b20_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a28b20(void*);
struct O_00a28b20 { int m(void*, void*, int, int, int); };
extern O_00a28b20 g_obj_00a28b20;
extern int g_tail_00a28b20;
void func_00a28b20()
{
    g_obj_00a28b20.m((void*)&g_00a28b20_0, (void*)&g_00a28b20_1, 596, 2, 0);
    tail_fn_00a28b20(&g_tail_00a28b20);
}