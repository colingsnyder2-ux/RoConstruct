// from server: 100% by colin
extern int g_00a2bb00_0;
extern int g_00a2bb00_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2bb00(void*);
struct O_00a2bb00 { int m(void*, void*, int, int, int); };
extern O_00a2bb00 g_obj_00a2bb00;
extern int g_tail_00a2bb00;
void func_00a2bb00()
{
    g_obj_00a2bb00.m((void*)&g_00a2bb00_0, (void*)&g_00a2bb00_1, 336, 31, 0);
    tail_fn_00a2bb00(&g_tail_00a2bb00);
}