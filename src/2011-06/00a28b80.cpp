// from server: 100% by colin
extern int g_00a28b80_0;
extern int g_00a28b80_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a28b80(void*);
struct O_00a28b80 { int m(void*, void*, int, int, int); };
extern O_00a28b80 g_obj_00a28b80;
extern int g_tail_00a28b80;
void func_00a28b80()
{
    g_obj_00a28b80.m((void*)&g_00a28b80_0, (void*)&g_00a28b80_1, 660, 2, 0);
    tail_fn_00a28b80(&g_tail_00a28b80);
}