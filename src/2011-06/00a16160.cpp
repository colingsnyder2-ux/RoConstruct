// from server: 100% by colin
extern int g_00a16160_0;
extern int g_00a16160_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a16160(void*);
struct O_00a16160 { int m(void*, void*, int, int, int); };
extern O_00a16160 g_obj_00a16160;
extern int g_tail_00a16160;
void func_00a16160()
{
    g_obj_00a16160.m((void*)&g_00a16160_0, (void*)&g_00a16160_1, 180, 31, 0);
    tail_fn_00a16160(&g_tail_00a16160);
}