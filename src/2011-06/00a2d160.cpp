// from server: 100% by colin
extern int g_00a2d160_0;
extern int g_00a2d160_1;
extern int g_00a2d160_2;
extern int g_00a2d160_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2d160(void*);
struct O_00a2d160 { int m(void*, void*, void*, void*, int); };
extern O_00a2d160 g_obj_00a2d160;
extern int g_tail_00a2d160;
void func_00a2d160()
{
    g_obj_00a2d160.m((void*)&g_00a2d160_0, (void*)&g_00a2d160_1, (void*)&g_00a2d160_2, (void*)&g_00a2d160_3, 31);
    tail_fn_00a2d160(&g_tail_00a2d160);
}