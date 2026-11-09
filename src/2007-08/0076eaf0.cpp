// from server: 100% by colin
extern int g_0076eaf0_0;
extern int g_0076eaf0_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076eaf0(void*);
struct O_0076eaf0 { int m(void*, void*, int, int); };
extern O_0076eaf0 g_obj_0076eaf0;
extern int g_tail_0076eaf0;
void func_0076eaf0()
{
    g_obj_0076eaf0.m((void*)&g_0076eaf0_0, (void*)&g_0076eaf0_1, 344, 4);
    tail_fn_0076eaf0(&g_tail_0076eaf0);
}