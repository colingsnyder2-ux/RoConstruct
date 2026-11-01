// from server: 100% by colin
extern int g_00a2d520_0;
extern int g_00a2d520_1;
extern int g_00a2d520_2;
extern int g_00a2d520_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2d520(void*);
struct O_00a2d520 { int m(void*, void*, void*, void*, int); };
extern O_00a2d520 g_obj_00a2d520;
extern int g_tail_00a2d520;
void func_00a2d520()
{
    g_obj_00a2d520.m((void*)&g_00a2d520_0, (void*)&g_00a2d520_1, (void*)&g_00a2d520_2, (void*)&g_00a2d520_3, 31);
    tail_fn_00a2d520(&g_tail_00a2d520);
}